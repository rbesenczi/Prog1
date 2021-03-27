//g++ vector_002.cpp -o vector_002 -Wall -fno-elide-constructors

#include "std_lib_facilities.h"

class My_vector {
	int sz;
	double* elem;

	void debug(const string& str)
	{
		cerr << this << "->" << str << " elem ptr: " 
			<< elem << endl;
	}

public:
	 explicit My_vector(int s): sz(s), elem{new double[s]} 
	{
		for (int i = 0; i < s; ++i) elem[i] = 0;
		debug("int constructor");
	}

	My_vector(initializer_list<double> lst): 
		sz(lst.size()), elem{new double[sz]} 
	{
		copy(lst.begin(), lst.end(), elem);
		debug("lst constructor");
	}

	My_vector(const My_vector& arg): 
		sz{arg.sz}, elem{new double[sz]}
	{
		copy(arg.elem, arg.elem+arg.sz, elem);
		debug("copy constructor");
	}

	My_vector& operator=(const My_vector& arg)
	{
		double* p = new double[arg.sz];
		copy(arg.elem, arg.elem+arg.sz, p);
		delete[] elem;
		elem = p;
		sz = arg.sz;
		debug("copy assignment");
		return *this;
	}

	My_vector(My_vector&& arg):
		sz{arg.sz}, elem{arg.elem}
	{
		arg.sz = 0;
		arg.elem = nullptr;
		debug("move constructor");
	}

	My_vector& operator=(My_vector&& arg)
	{
		delete[] elem;
		sz = arg.sz;
		elem = arg.elem;
		arg.sz = 0;
		arg.elem = nullptr;
		debug("move assignment");
		return *this;
	}

	~My_vector() { debug("destructor"); delete[] elem; }

	int size() const { return sz; }
	double get(int i) const { return elem[i]; }
	void set(int i, double val) { elem[i] = val; }

	double& operator[](int n){ return elem[n]; }
	const double& operator[](int n) const { return elem[n]; }
};

My_vector fill()
{
	My_vector t{10.2, 14.6, 20.1};

	return t;
}

My_vector glob(10);

int main()
{
	My_vector mv {15.2, 18.6, 120.1};

	for(int i = 0; i < mv.size(); ++i)
		cout << mv.get(i) << ' ';
	cout << endl;

	My_vector mv2 (mv);
	//My_vector mv2 = mv;

	for(int i = 0; i < mv2.size(); ++i)
		cout << mv2.get(i) << ' ';
	cout << endl;

	My_vector mv3 {15.2, 18.6, 120.1};

	mv3 = mv;

	for(int i = 0; i < mv3.size(); ++i)
		cout << mv3.get(i) << ' ';
	cout << endl;

	My_vector mv4 = fill();

	for(int i = 0; i < mv4.size(); ++i)
		cout << mv4.get(i) << ' ';
	cout << endl;

	My_vector mv5 {15.2, 18.6, 120.1};

	mv5 = fill();

	for(int i = 0; i < mv5.size(); ++i)
		cout << mv5.get(i) << ' ';
	cout << endl;

	My_vector mv6 (10);

	return 0;
}