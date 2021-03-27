#include "std_lib_facilities.h"

class My_vector {
	int sz;
	double* elem;
public:
	My_vector(int s): sz(s), elem{new double[s]} 
	{
		for (int i = 0; i < s; ++i) elem[i] = 0;
	}

	My_vector(initializer_list<double> lst): 
		sz(lst.size()), elem{new double[sz]} 
	{
		copy(lst.begin(), lst.end(), elem);
	}

	My_vector(const My_vector& arg): 
		sz{arg.sz}, elem{new double[sz]}
	{
		copy(arg.elem, arg.elem+arg.sz, elem);
	}

	My_vector& operator=(const My_vector& arg)
	{
		double* p = new double[arg.sz];
		copy(arg.elem, arg.elem+arg.sz, p);
		delete[] elem;
		elem = p;
		sz = arg.sz;
		return *this;
	}

	~My_vector() { delete[] elem; }

	int size() const { return sz; }
	double get(int i) const { return elem[i]; }
	void set(int i, double val) { elem[i] = val; }
};

int main()
{
	My_vector mv {10.2, 14.6, 20.1};

	cout << "mv size==" << mv.size() << endl;

	for(int i = 0; i < mv.size(); ++i)
		cout << mv.get(i) << ' ';
	cout << endl;

	My_vector mv2 (mv);

	for(int i = 0; i < mv2.size(); ++i)
		cout << mv2.get(i) << ' ';
	cout << endl;

	My_vector mv3 {15.2, 19.6, 100.1};

	for(int i = 0; i < mv3.size(); ++i)
		cout << mv3.get(i) << ' ';
	cout << endl;

	mv3 = mv;

	for(int i = 0; i < mv3.size(); ++i)
		cout << mv3.get(i) << ' ';
	cout << endl;

	return 0;
}