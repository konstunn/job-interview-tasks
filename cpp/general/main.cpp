
#include <iostream>

using std::cout;
using std::endl;

class A 
{
	public:
	A  () { cout << "A::A()"  << endl; }
	virtual ~A () { cout << "A::~A()" << endl; }
	void foo() { cout << "A::foo()" << endl; }
	void bar () { cout << "A::bar()" << endl; }
};

class B : public A
{
	public:
	B  () { cout << "B::B()"  << endl; }
	~B () { cout << "B::~B()" << endl; }
	virtual void foo() { cout << "B::foo()" << endl; }
	void bar() { cout << "B::bar()" << endl; }
};


class C : public B
{
	public:
	C  () { cout << "C::C()"  << endl; }
	~C () { cout << "C::~C()" << endl; }
	void foo() { cout << "C::foo()" << endl; }
	void bar() { cout << "C::bar()" << endl; }
};

class D : public C
{
	public:
	D () { cout << "C::C()" << endl; }
};

void foo (A & a) {
	a.foo();	
}

int main ()
{
	cout << "A *p = new C();" << endl;
	A * p = new C();
	p->foo ();
	delete p;
}
