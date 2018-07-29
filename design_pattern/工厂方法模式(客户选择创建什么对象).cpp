/*
工厂方法模式不同于简单工厂模式的地方在于工厂方法模式把对象的创建过程放到里子类里。这样工厂父对象和产品父对象一样，
可以是抽象类或者接口，只定义相应的规范或操作，不涉及具体的创建或实现细节。
*/

//==============================定义子类和基类
#pragma once
class IProduct
{
public:
	IProduct(void);
	virtual ~IProduct(void);
};
 
#pragma once
#include "iproduct.h"
class IPad :
	public IProduct
{
public:
	IPad(void);
	~IPad(void);
};
 
#pragma once
#include "iproduct.h"
class IPhone :
	public IProduct
{
public:
	IPhone(void);
	~IPhone(void);
};

//===================工厂类和子类，用到上面的对象
#pragma once
#include"IProduct.h"
 
class IFactory
{
public:
	IFactory(void);
	virtual ~IFactory(void);    //基类虚函数不实现可以吗？？？
 
	virtual IProduct* getProduct();     //后面子类可重写
};
 
 
#pragma once
#include "ifactory.h"
class IPadFactory :
	public IFactory
{
public:
	IPadFactory(void);
	~IPadFactory(void);
 
	virtual IProduct* getProduct();
};
 
 
#pragma once
#include "ifactory.h"
class IPhoneFactory :
	public IFactory
{
public:
	IPhoneFactory(void);
	~IPhoneFactory(void);
 
	virtual IProduct* getProduct();
};

//===============子类实现
    #include "StdAfx.h"
    #include "IPadFactory.h"
    #include"IPad.h"
     
    IPadFactory::IPadFactory(void)
    {
    }
     
     
    IPadFactory::~IPadFactory(void)
    {
    }
     
    IProduct* IPadFactory::getProduct()
    {
    	return new IPad();
    }
     
     
    #include "StdAfx.h"
    #include "IPhoneFactory.h"
    #include"IPhone.h"
     
    IPhoneFactory::IPhoneFactory(void)
    {
    }
     
     
    IPhoneFactory::~IPhoneFactory(void)
    {
    }
     
     
    IProduct* IPhoneFactory::getProduct()
    {
    	return new IPhone();
    }
    
//================   其实是根据基类指针来调用的
#include "stdafx.h"
#include"IFactory.h"
#include"IPadFactory.h"
#include"IPhoneFactory.h"
#include"IProduct.h"
 
 
int _tmain(int argc, _TCHAR* argv[])
{
	IFactory *fac = new IPadFactory();
	IProduct *pro = fac->getProduct();
 
	fac = new IPhoneFactory();
	pro = fac->getProduct();
	return 0;
}
