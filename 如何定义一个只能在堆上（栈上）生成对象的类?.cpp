1、只能建立在堆上

        类对象只能建立在堆上，就是不能静态建立类对象，即不能直接调用类的构造函数。
        
        将析构函数设为私有，类对象就无法建立在栈上了。代码如下：
        
        class  A  
        {  
        public :  
            A(){}  
            void  destory(){ delete   this ;}  
        private :  
            ~A(){}  
        };  
        
2、只能建立在栈上   //类里还有new操作符呢,一直忽略了

        只有使用new运算符，对象才会建立在堆上，因此，只要禁用new运算符就可以实现类对象只能建立在栈上。将operator new()设为私有即可。代码如下：
        
        class  A  
        {  
        private :  
            void * operator  new ( size_t  t){}      // 注意函数的第一个参数和返回值都是固定的   
            void  operator  delete ( void * ptr){}  // 重载了new就需要重载delete   
        public :  
            A(){}  
            ~A(){}  
        }; 

