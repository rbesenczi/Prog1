#include <iostream>

class B {
public:
	virtual void f() const
			{ std::cout << "B::f\n";  print_message(8.5); }
	void g() const { std::cout << "B::g\n"; }
	void print_message(int a) const 
			{ std::cout << "Message: " << a << std::endl;}
};

struct D : B {
	void f() const override 
		{ std::cout << "D::f\n"; print_message(8.5); }
	void g() { std::cout << "D::g\n"; }
	void print_message(double a) const
				{ std::cout << "Message: " << a << std::endl;}
};

struct DD : B {
	void f() const { std::cout << "DD::f\n"; }
	void g() const { std::cout << "DD::g\n"; }
};

void call(const B& b)
{
	b.f();
	b.g();
}

int main()
{
	std::cout << "Call with call().\n";

	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	std::cout << "Call with local.\n";

	b.f();
	b.g();

	d.f();
	d.g();

	dd.f();
	dd.g();

	std::cout << "Call with ref:\n";

	B& bref {dd};
	bref.f();
	bref.g();

	std::cout << "Call with ptr:\n";

	B* bptr {&d};
	bptr->f();
	bptr->g();

	return 0;
}
