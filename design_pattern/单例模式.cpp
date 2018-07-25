//懒汉线程安全
class Singleton
{
public:
	static Singleton& Instance()   //Instance()作为静态成员函数提供里全局访问点
	{
        if(m_instance== NULL)//先判断实例是否存在，不存在再加锁，避免多次加锁与解锁操作
        {
            Lock();	//上锁
            if(m_instance== NULL)	//如果还未实例化，即可实例话，反之提供实例的引用
                m_instance = new Singleton();
            Unlock();	//解锁
        }
        return *m_instance; //返回指针的话可能会误被 delete，返回引用安全一点
}
private:
    Singleton(); //这里将构造，析构，拷贝构造，赋值函数设为私有，杜绝了生成新例
    ~Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    static Singleton* m_instance;
};//源文件
Singleton* Singleton::ps = NULL;


//------恶汉本身就安全----
class singleton
{
protected:
    singleton(){}
private:
    static singleton* instance;//static的，类一加载，就会初始化
public:
    static singleton* initance();      //给外部进行调用
};
singleton* singleton::instance = new singleton();
singleton* singleton::initance()
{
    return instance;
}
