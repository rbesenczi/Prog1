#include <iostream>

struct A {
	virtual void pvf() const = 0;
};

class B : public A {
public:
	virtual void f() const
			{ std::cout << "B::f\n";  print_message(8.5); }
	void g() const { std::cout << "B::g\n"; }
	void print_message(int a) const 
			{ std::cout << "Message: " << a << std::endl;}
	void pvf() const { std::cout << "B::pvf()\n"; }
};

struct D : B {
	void f() const override 
		{ std::cout << "D::f\n"; print_message(8.5); }
	void g() { std::cout << "D::g\n"; }
	void print_message(double a) const
				{ std::cout << "Message: " << a << std::endl;}
	void pvf() const { std::cout << "D::pvf()\n"; }
};

struct DD : B {
	void f() const { std::cout << "DD::f\n"; }
	void g() const { std::cout << "DD::g\n"; }
	void pvf() const { std::cout << "DD::pvf()\n"; }
};

void call(const B& b)
{
	b.pvf();
	b.f();
	b.g();
}

int main()
{
	std::cout << "Call with call().\n";

	//A a; // error
	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	std::cout << "Call with local.\n";

	b.pvf();
	b.f();
	b.g();

	d.pvf();
	d.f();
	d.g();

	dd.pvf();
	dd.f();
	dd.g();

	std::cout << "Call with ref:\n";

	B& bref {dd};
	bref.pvf();
	bref.f();
	bref.g();

	std::cout << "Call with ptr:\n";

	B* bptr {&d};
	bptr->pvf();
	bptr->f();
	bptr->g();

	return 0;
}
