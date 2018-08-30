//https://blog.csdn.net/hechao3225/article/details/71155659

回调函数最常见的应用就是STL里的泛型算法，如快排的使用就会用到回调机制。
template<typename _RAIter, typename _Compare>
        void 
        sort(_RAIter, _RAIter, _Compare);

这个原型中第三个参数即回调函数入口，需要用户提供一个比较方法，比如对于一个vector<pair<int,int> >容器，需要将其每个元素按pair的second进行降序排列，
实现的比较函数如下：
bool cmpByValue(const pair<int,int> &x,const pair<int,int> &y)
{
    return x.second>y.second;
}

实现上述比较函数后，可以将函数名作为参数传入sort()，函数名传参时隐式转化为函数指针，这是函数指针实现回调的一种典型用法。
sort(vec_test.begin(),vec_test.end(),cmpByValue);

//你看这里sort函数就只是取个类型即可，也没形参来接受变量，感觉就是自动推导类型用

