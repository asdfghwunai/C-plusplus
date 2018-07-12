总结：
malloc/free 和 new/delete的区别？

相同点：都是从堆上申请空间，用户需要自己来管理。
不同点：
1.malloc是函数，有一个参数，返回void*类型（需要强制类型转换）。
new是关键字，不是函数，返回类型 指针类型。

2.malloc要检测是否申请空间成功，不会调用构造函数。
new申请空间，调用构造函数。若调用失败，会抛出异常。

3.free是函数，只有一个参数，释放空间地址，不会调用析构函数。
delete是关键字，释放空间地址时，调用析构函数。
底层做的工作：
1.new T类型

（1）调用operator new(sizeof(T))，该函数的函数原型为void* operator new(size_t size)。
（2）调用operator new中的malloc(set_new_handle)，如果申请成功，返回；申请失败（可能原因是内存空间不足），采取应对措施set_new_handler，如果应对措施没有，抛出一个异常。
（3）调用一个构造函数。构造函数显示给出，编译器自动合成。
2.delete p

（1）调用一个析构函数。
（2）调用operator delete，释放空间地址。
（3）调用free函数。
3.new T[N]

（1）调用operator new[] (N*sizeof(T))，会在申请的空间的头部多给4个字节的空间，用来存放N。
（2）调用operator new函数
（3）调用malloc函数
（4）调用N次构造函数，构造出来N个对象。
（5）返回第一个对象所在的首地址，不是原空间的地址，而是原空间的地址向后偏移4个位置。
4.delete[] p       

（1）取出N（在空间的前四个字节中）。      //说明确实有偏移啊

*((int*)p-1)
*[(int*)((int)p-4)]

    1
    2

（2）调用N次析构函数。
（3）调用operator delete[] (p)。
（4）调用operator delete。
（5）调用free函数。
