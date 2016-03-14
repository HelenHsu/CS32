#include <iostream>
#include <string>
using namespace std;
class base
{
 public:
	base(string set):m_1(set){cout<<"Base constructor called."<<endl;}
	virtual ~base(){cout<<"Base destructor called."<<endl;cout<<endl;}
	string which(){return m_1;}	//non virtual function, the common member for every derived class
	virtual void f2() =0;		//pure virtual function, n/a for base but some derived class has this
	virtual void f3() {cout<<"This function can be overwrite by derived class." <<endl;}
 private:
	string m_1;
};

class derived1:public base		//except constructor and destructor, every items are the same as base
{
 public:
	derived1():base("derived1 set."){cout<<"Derived class 1 constructor called."<<endl;}
	~derived1(){cout<<"Derived class 1 destructor called."<<endl;}
	virtual void f2() {cout<<"pure virtual function must be implemented"<<endl;}

};

class derived2:public base	//derived2 has extra member, extra function, overwrite f3 function
{
 public:
	derived2(string msg):base("derived2 set."),m_2(msg){cout<<"Derived class 2 constructor called."<<endl;}
	~derived2(){cout<<"Derived class 2 destructor called"<<endl;}
	void f1(){cout<<"This is extra function of derived2 which output extra member."<<endl; cout<<"m_2= "<<m_2<<endl;}
	virtual void f2() {cout<<"pure virtual function must be implemented."<<endl;}
	virtual void f3() const{cout<<"Derived2 changes the original function."<<endl;}
 private:
	string m_2;
};


int main()
{

	base *b1,*b2;
	b1 = new derived1;
	cout<<b1->which()<<endl;
	b1->f2();
	b1->f3();
	delete b1;

	b2 = new derived2("derived2 is special.");
	cout<<b2->which()<<endl;
//	b2->f1();	//the base pointer cannot call the non virtual function of derived2
	b2->f2();
	b2->f3();
	delete b2;

	derived2 *D2 = new derived2("derived2 is so special");
	cout<<D2->which()<<endl;	//call the function of base using derived2 pointer
	D2->f1();
	delete D2;
}

