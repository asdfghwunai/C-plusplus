 没有加 const 的函数不能在 const 对象上使用.
为了让你的函数能够在更多的情况下正常使用, 你最好对所有不会修改对象的函数加 const

Box operator+(const Box&);  //返回值看来随意

classname (const classname &obj) {
   // 构造函数的主体
}


我居然把这么重要的俩函数当成形式任意的。。。。
