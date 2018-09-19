#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void f() {cout<<"Base::f()"<<endl;}

};

class Derive: public Base
{
public:
    virtual  void f() {cout<<"Derive::f()"<<endl;}
    virtual  void f2() {cout<<"Derive::f1()"<<endl;}

};


int main()
{

    Base *pbase1  = new Derive();
    Derive* pderive1 = static_cast<Derive *>(pbase1);
    pderive1->f(); // Derive::f()
    
    Base* pbase2 = new Base();
    Derive * pderive2 = static_cast<Derive *>(pbase2);
    pderive2->f();  // Base::f()     //根还是在基类
    pderive2->f2(); // throw exception "Access violation reading"

    delete pbase1;
    delete pbase2;

}

//======================================
#include <iostream>
using namespace std;

class Base
{
public:
virtual void f() {cout<<"Base::f()"<<endl;}

};

class Derive: public Base
{
public:
virtual void f() {cout<<"Derive::f()"<<endl;}
virtual void f2() {cout<<"Derive::f1()"<<endl;}

};

int main()
{

Base *pbase1 = new Derive();
Derive* pderive1 = dynamic_cast<Derive *>(pbase1); //down-cast
pderive1->f(); // Derive::f()

Base* pbase2 = new Base();
Derive * pderive2 = dynamic_cast<Derive *>(pbase2); //up-cast

if ( pderive2) // NULL  //居然真等于NULL啊，看来不能向下转型。这东西还是听对象的具体类型的，不是看=左边的指针
{
pderive2->f();
pderive2->f2();
}

delete pbase1;
delete pbase2;

}
