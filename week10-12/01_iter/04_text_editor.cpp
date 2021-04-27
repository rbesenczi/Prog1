#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <fstream>

using Line = std::vector<char>;

class Text_iterator{
	std::list<Line>::iterator ln;
	Line::iterator pos;

public:
	Text_iterator(std::list<Line>::iterator ll, Line::iterator pp): ln{ll}, pos{pp} {}
	
	std::list<Line>::iterator get_line() { return ln; }
	Line::iterator get_pos() { return pos; }

	char& operator*(){ return *pos; }
	Text_iterator& operator++();
	bool operator==(const Text_iterator& other) const
		{ return ln == other.ln && pos == other.pos; }
	bool operator!=(const Text_iterator& other) const
		{ return !(*this==other); }
};

struct Document {
	std::list<Line> line;
	Document() { line.push_back(Line{}); }

	Text_iterator begin(){
		return Text_iterator(line.begin(), (*line.begin()).begin());
	}

	Text_iterator end(){
		auto last = line.end();
		--last;
		return Text_iterator(last, (*last).end());
	}

	Text_iterator erase (Text_iterator pos);
	Text_iterator insert (Text_iterator pos, const char& ch);
	void concat (Text_iterator& pos);
	void break_ln (Text_iterator pos);
	void find_replace (Text_iterator first, Text_iterator last,
		const std::string& find, const std::string& replace);
};

std::istream& operator>>(std::istream& is, Document& d){

	for (char ch; is.get(ch); ){
		d.line.back().push_back(ch);
		if (ch == '\n')
			d.line.push_back(Line{});
	}
	if (d.line.back().size())
		d.line.push_back(Line{});

	return is;
}

Text_iterator& Text_iterator::operator++(){
	++pos;
	if (pos==(*ln).end()){
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}

void print (Document& d){
	for (auto p : d) std::cout << p;
	std::cout << std::endl;
}

void print_found (Document& d, Text_iterator p, int char_count){
	
	int i = 0;
	for ( ; i < char_count; ++p) {
		std::cout << *p;
		++i;
	}
	std::cout << std::endl;
}


template<typename Iter>
void advance(Iter& p, int n){
	while (0<n) { ++p; --n; }
}

void erase_line(Document& d, int n){
	if (n<0 || d.line.size()-1<=n) return;
	auto p = d.line.begin();
	advance (p, n);
	d.line.erase(p);
}

int char_count(Document& d)
{
    Text_iterator iter = d.begin();
    int ctr = 0;
    while (iter != d.end()) {
        ++iter;
        ++ctr;
    }
    return ctr;
}

template<class Iter> bool match (Iter first, Iter last, const std::string& s){
	std::string::const_iterator si = s.begin();
	while (first != last && si != s.end()){
		if (*first != *si) return false;
		++first;
		++si;
	}
	return true;
}
	
template<class Iter, class T> Iter find(Iter first, Iter last, const T& val){
	
	Iter p = first;
	while (p != last) {
		if (*p == val) return p;
		++p;
	}
	return p;
}

Text_iterator find_txt(Text_iterator first, Text_iterator last, const std::string& s){
	
	if (s.size()==0) return last;
	char first_char = s[0];
	while (true){
		auto p = find(first, last, first_char);
		if (p==last || match(p, last, s)) return p;
		first = ++p;
	}
}

Text_iterator Document::erase (Text_iterator pos){

	std::list<Line>::iterator list_it = pos.get_line();
	Line::iterator line_it = pos.get_pos();
	line_it = (*list_it).erase(line_it);
	return Text_iterator(list_it, line_it);
}

Text_iterator Document::insert (Text_iterator pos, const char& ch){

	std::list<Line>::iterator list_it = pos.get_line();
	Line::iterator line_it = pos.get_pos();
	line_it = (*list_it).insert(line_it, ch);
	return Text_iterator(list_it, line_it);
}

void Document::concat (Text_iterator& pos){

	std::list<Line>::iterator current_line = pos.get_line();
	Line::iterator line_pos = pos.get_pos();
	Line::size_type index = line_pos - (*current_line).begin();
	std::list<Line>::iterator next_line = current_line;
	++next_line;
	(*current_line).insert((*current_line).end(), (*next_line).begin(), (*next_line).end());

	//Validate iterator
	pos = Text_iterator (current_line, (*current_line).begin() + index);

	//Erase line
	std::list<Line>::iterator list_it = begin().get_line();

	int line_ctr = 0;
	while (list_it != next_line) {
		++list_it;
		++line_ctr;
	}

	erase_line (*this, line_ctr);

}

void Document::break_ln (Text_iterator pos){

	std::list<Line>::iterator current_line = pos.get_line();
	std::list<Line>::iterator next_line = current_line;
	next_line++;
	(*next_line).insert((*next_line).begin(), pos.get_pos() + 1, (*current_line).end());
	(*current_line).erase(pos.get_pos()+1, (*current_line).end());
}

void Document::find_replace (Text_iterator first, Text_iterator last,
	const std::string& find, const std::string& replace){

	if (find == "") return;

	Text_iterator pos = find_txt (first, last, find);

	while (pos != last){
		std::string::const_iterator find_it = find.begin();
		std::string::const_iterator repl_it = replace.begin();
		while (find_it != find.end() && repl_it != replace.end()) {
			if (*find_it != *repl_it) {
				*pos = *repl_it;
				if (*find_it == '\n'){ //Ha a keresendőben van egy újsor karakter
					concat (pos);
				}
				if (*repl_it == '\n') break_ln(pos); //Ha az új szövegben van egy újsor
			}
			++pos;
			++find_it;
			++repl_it;
		}
		
		while (find_it != find.end()){
			if (*pos == '\n') concat (pos);
			pos = erase (pos);
			++find_it;
		}

		while (repl_it != replace.end()){
			pos = insert (pos, *repl_it);
			if (*repl_it == '\n') break_ln(pos);
			++pos;
			++repl_it;
		}

		pos = find_txt (pos, last, find);
	}
}

int main(int argc, char** argv){
	
	std::ifstream ifs (argv[1]);

	if (!ifs) {
		std::cout << "file not found\n";
		return 0;
	}
	
	Document my_doc;
	ifs >> my_doc;

	std::string some_text = argv[2];
	auto p = find_txt(my_doc.begin(), my_doc.end(), some_text);
	if (p == my_doc.end())
		std::cout << "Not found\n";
	else
		print_found(my_doc, p, some_text.size());

	std::cout << "Number of chars: " << char_count(my_doc) << std::endl;

	erase_line(my_doc, 2);

	print(my_doc);

	std::cout << "Number of chars: " << char_count(my_doc) << std::endl;

	std::string find = "stationary";
	std::string replace = "not stationary";

	my_doc.find_replace( my_doc.begin(), my_doc.end(), find, replace);

	print(my_doc);
	
	return 0;
}	