/*
标准函数名不加<T>，但是参数要加T啊
*/

#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

template<class T>
class SmartPtr
{
public:
    SmartPtr(T *p);  //函数名不用写成SmartPtr<T>这样，想想也太冗余了
    ~SmartPtr ();
    SmartPtr(const SmartPtr<T> &other);   //但是参数你得这样写，是规定
    SmartPtr<T>& operator=(const SmartPtr<T> &other);

private:
    T *ptr;
    int *use_count;

};

template<class T>        //又忘加这个了
SmartPtr<T>::SmartPtr(T *p)
{
    ptr=p;
    use_count=new int(1);
}

template<class T>
SmartPtr<T>::~SmartPtr()
{
    if(--(*use_count)==0)
    {
        delete ptr;
        delete use_count;     //删除要删除两样
        ptr= nullptr;
        use_count= nullptr;
    }
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &other)
{
    ptr=other.ptr;
    use_count=other.use_count;
    (*use_count)++;    //引用计数加1
}

template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &other)
{
    if(--(*use_count)==0)    //引用计数减1
    {
        delete ptr;
        delete use_count;     //删除要删除两样
        ptr= nullptr;
        use_count= nullptr;
    }
    else
    {
        ptr=other.ptr;
        use_count=other.use_count;
        (*use_count)++;    //引用计数加1
    }
    return *this;
}

int main()
{
    SmartPtr<int> s1(new int(1));
    SmartPtr<int> s2(s1);

    return 0;
}
