/*
重载：一个类里实现若干重载的方法，这些方法的名称相同而参数形式不同(在一个作用域)
重写:一般用于子类在继承父类时，重写（覆盖）父类中的方法.不能是static，必须是virtual 一个没this指针，一个需要this指针
重定义:派生类定义了某个函数，该函数的名字与基类中函数名字一样。（只要函数名一样，不是virtual，不在一个作用域）
*/

#include<iostream>
using namespace std;

class Base

{

private:
	virtual void display() 
	{ 
		cout << "Base display()" << endl; 
	}

	void say() 
	{ 
		cout << "Base say()" << endl; 
	}

public:
	void exec() 
	{ 
		display(); 
		say(); 
	}

	void fun1(string a) 
	{
		cout << "Base fun1(string)" << endl;
	}

	void fun1(int a) 
	{ 
		cout << "Base fun1(int)" << endl; 
	}//overload，两个fun1函数在Base类的内部被重载

};

	class ChildA :public Base

	{

	public:

		void display() 
		{ 
			cout << "ChildA display()" << endl; 
		}//override，基类中的display为虚函数，故此处为重写（覆盖）

		void fun1(int a, int b) 
		{ 
			cout << "ChildA fun1(int,int)" << endl; 
		}//redefining，fun1函数在Base类中不为虚函数，故此处为重定义

		void say() 
		{
			cout << "ChildA say()" << endl;
		}//redefining

	};

	class ChildB :public Base

	{

	public:

		void fun1(int a) 
		{
			cout << "ChildB fun1(int)" << endl; 
		}//redefining

	};



	int main()

	{
		ChildA a;

		Base* b = &a;

		b->exec(); //display():version of DeriveA call(polymorphism) //say():version of Base called(allways )

		//b里边的函数display被A类重写（覆盖），say还是自己的


		a.exec(); //same result as last statement   //发生这种情况谁让childA没有exec呢？
		a.say();
		ChildB c;
		c.fun1(1); //version of DeriveB called

		while (1);
		return 0;
	}
  
  //我打b->say(); 居然不可访问，为何只认自己的say，我感觉是指针本体还在基类，不过是执行一个函数时看子类是否重写了，是就跳过去执行，执行完还回来的，
  如果执行的不是virtual就执行自己的
  
  /*   
ChildA display()
Base say()
ChildA display()
Base say()
ChildA say()
ChildB fun1(int)
  */
