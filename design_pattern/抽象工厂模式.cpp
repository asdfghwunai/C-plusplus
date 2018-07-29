/*
在系统里a,b,c三个组件必须同时使用，但是a的同类 a1和a2这三种方法有共同特点但是是互斥的，b,b1,b2和c,c1,c2和a/a1/a2是一样的。
就比如说创建在不同操作系统的视窗环境下都能够运行的系统时，Unix下面有unixButton和 unixText，
Win下面也有winButton和winText，unixButton和unixText必须在一个系统unix里面用，而winButton和winText只能在Win下面用。
但是winButton和unixButton这两种东西都是有相同的特点的，比如说按下去之后会触发事件，比如说他上面有文字描述等等，
但是winButton和unixButton却又是不可以混用的。

     那么此问题就可以用抽象工厂很好的解决：
     在抽象工厂模式中如何选择使用 winButton ,winText，有具体的工厂类winFactory来负责，因为他们含有选择合适的产品对象的逻辑，
     所以是与应用系统的商业逻辑紧密相关的。而抽象工厂类来负责定义接口，他才是抽象工厂模式的核心。
     而winButton/macButton则是一种产品族，有共同的特点，他们具体特点有抽象产品类或者接口来定义和描述。但是他们具体的实现有具体的产品类负责，
     这些是客户端最终想要的东西，所以其内部一定充满了应用系统的商业逻辑（触发逻辑/样式逻辑等）。
*/

    // CplusplusAbstractFactory.cpp : Defines the entry point for the console application.
    //
     
    #include "stdafx.h"
    #include<typeinfo>
    // "AbstractProductA" 草食动物
    class Herbivore
    {
    };
     
    // "AbstractProductB" 食肉动物
    class Carnivore
    {
    public:
    	// Methods
    	virtual void Eat( Herbivore *h ) {};
    };
     
    // "ProductA1"
    class Wildebeest : public Herbivore
    {
    };
     
    // "ProductA2"
    class Bison : public Herbivore
    {
    };
     
    // "ProductB1"
    class Lion : public Carnivore
    {
     
    public:
    	// Methods
    	void Eat( Herbivore *h )
    	{
    		// eat wildebeest	 
    		printf("Lion eats %s\n",typeid(h).name());
    	}
    };
     
    // "ProductB2"
    class Wolf : public Carnivore
    {
     
    public:
    	// Methods
    	void Eat( Herbivore *h )
    	{
    		// Eat bison
    		printf("Wolf eats %s\n",typeid(h).name());
    	}
    };
     
    // "AbstractFactory"
    class ContinentFactory
    {
    public:
    	// Methods
    	virtual Herbivore* CreateHerbivore()
    	{
    		return new Herbivore();
    	}
    	virtual Carnivore* CreateCarnivore()
    	{
    		return new Carnivore();
    	}
    };
     
    // "ConcreteFactory1"
    class AfricaFactory : public ContinentFactory
    {
    public:
    	// Methods
    	Herbivore* CreateHerbivore()
    	{ 
    		return new Wildebeest(); 
    	}
     
    	Carnivore* CreateCarnivore()
    	{ 
    		return new Lion(); 
    	}
    };
     
    // "ConcreteFactory2"
    class AmericaFactory : public ContinentFactory
    {
    public:
    	// Methods
    	Herbivore* CreateHerbivore()
    	{ 
    		return new Bison(); 
    	}
     
    	Carnivore* CreateCarnivore()
    	{ 
    		return new Wolf(); 
    	}
    };
     
     
     
    // "Client"
    class AnimalWorld
    {
    private:
    	// Fields
    	Herbivore* herbivore;
    	Carnivore* carnivore;
     
    public:
    	// Constructors
    	AnimalWorld( ContinentFactory *factory )
    	{
    		carnivore = factory->CreateCarnivore();
    		herbivore = factory->CreateHerbivore();
    	}
     
    	// Methods
    	void RunFoodChain()
    	{ 
    		carnivore->Eat(herbivore); 
    	}
    };
     
     
    int _tmain(int argc, _TCHAR* argv[])
    {
    	// Create and run the Africa animal world
    	ContinentFactory *africa = new AfricaFactory();
    	AnimalWorld *world = new AnimalWorld( africa );
    	world->RunFoodChain();
     
    	// Create and run the America animal world
    	ContinentFactory *america = new AmericaFactory();
    	world = new AnimalWorld( america );
    	world->RunFoodChain();
     
    	return 0;
    }
