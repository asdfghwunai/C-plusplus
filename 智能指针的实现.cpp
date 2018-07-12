#include <iostream>
using namespace std;

int main()
{
    int *ptr = new(nothrow) int(0);   //C++也可以采用new nothrow的方法禁止抛出异常而返回NULL； 
    if(!ptr)
    {
        cout << "new fails."
        return 0;
    }
    delete ptr;
    ptr = nullptr;
    return 0;
}
