#### 1.区分前置与后置运算符
后置版本额外接受一个不被使用的int类型的参数
```
StrBlobPtr operator++(int);//后置运算符
//后置运算符返回的应该是对象的原值
```
----
#### 2.标准库的function类型（定义在functional头文件中）

	function<T> f;
	//f是一个用来存储可调用对象function，调用形式与函数类型T相同
	function<T> f(nullptr);//显式的构造一个空的function
	function<T> f(obj);//f中存储可调用对象的副本
	f; //f作为条件：含有可调用对象为真，否则为假
	f(args);//调用f中的对象，参数是args

	定义为function<T>的成员的类型:
	result_type 该function类型的可调用对象的返回类型
	argument_type 如果函数只用一个实参则是该类型的同义词
	first_argument_type 代表第一个实参的类型
	second_argument_type 代表第二个实惨的类型
##### function使用样例：
	function(int(int,int)) f = add;
	function(int(int,int)) f = divide();
	funcyion(int(int,int)) f = [](int i,int j)
								{ return i*j; };
	//三种使用function的形式

----
#### 3.类型转换运算符
	operator type() const;
	是一种特殊的成员函数，它负责将一个类类型的值转换成其他类型
	type可以表示任何除了void以外的能作为函数类型的类型
----
#### 4.当我们使用两个用户定义的类型转换时，如果转换函数之前或之后存在标准类型转换，则标准类型转换将决定最佳匹配到底是哪个。
***避免二义性的两个经验***
1. 不要令两个类执行相同的类型转换：如果FOO类中有个接受Bar类对象的构造函数，不要在Bar类中再定义转换目标是Foo类的类型转换运算符
2. 避免转换目标是内置算数类型的类型转换
----
#### 5.派生类必须在其内部对所有重新定义的虚函数进行声明，可以在这样的函数之前加上virtual关键字，也可以在该函数形参列表之后加上一个override关键字
----
#### 6.类的继承用的是：不是extrend，后者是申明后面的变量在其他文件中。集成分为多种继承，默认是private的，建议声明的时候加上public。
	class Extren : public Basic{};
public继承方式相当于获得了基类所有的public函数

#### 如果想要防止继承的发生就在类名后面跟一个关键字final
----
#### 7.纯虚函数就是在函数后面加上=0.
	double	net_price(size_t) const =0;
	有纯虚函数的基类叫做抽象基类，抽象基类是不能创建对象的。
----
#### 8.虚函数的调用会发生动态绑定，不是虚函数的话则只会发生静态绑定，实际调用函数的版本由指针的静态类型决定
