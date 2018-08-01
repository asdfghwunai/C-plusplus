#include<iostream>
using namespace std;

class Singlelon
{

private:
	static Singlelon *p;
	Singlelon(){ cout << "构造函数"<<endl; }
	Singlelon(const Singlelon& m){}
	Singlelon& operator=(const Singlelon& m);
public:
	static Singlelon* instance();
};

Singlelon* Singlelon::instance()
{
	if (p == NULL)
		p = new Singlelon();
	return p;
}

Singlelon * Singlelon::p = NULL;

int main()
{
	Singlelon* s1=Singlelon::instance();

	Singlelon* s2 = Singlelon::instance();

	while (1);

	return 0;
}
