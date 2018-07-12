函数模板的特化：当函数模板需要对某些类型进行特别处理，称为函数模板的特化。

例如，我们编写了一个泛化的比较程序

template <class T>
int compare(const T &left, const T&right)
{
    std::cout <<"in template<class T>..." <<std::endl;
    return (left - right);
}

 

这个函数满足我们的需求了么，显然不，它支持常见int, float等类型的数据的比较，但是不支持char*(string)类型。

所以我们必须对其进行特化，以让它支持两个字符串的比较,因此我们实现了如下的特化函数。

template < >
int compare<const char*>(const char* left, const char* right)
{
    std::cout <<"in special template< >..." <<std::endl;

    return strcmp(left, right);
}

 
也可以
template < >
int compare(const char* left, const char* right)
{
    std::cout <<"in special template< >..." <<std::endl;

    return strcmp(left, right);
}
