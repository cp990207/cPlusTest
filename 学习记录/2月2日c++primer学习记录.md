#### 1.局部静态变量 static 在程序执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁
```
size_t count_callls()
{
	static size_t ctr = 0;//size_t是为了方便移植规定的无符号整数
	++ctr;
	return ctr;
}
```
----
#### 2.使用引用避免拷贝，如果不会改变形参的值那就用const引用。
```
bool isShorter(const string &str1,const string &str2)
//比较的代码
```
----
#### 3.数组形参
数组无法拷贝--无法以值传递的方式使用数组参数
数组会被转化成指针--传递一个数组时实际上是传递一个指向数组首元素的指针
```
void print(const int*)
void print(const int[])
void print(const int[10])//想要规定大小，但是不能
//以上三种定义方式时等价的
```

数组是以指针的形式传递给参数的，所以函数并不知道数组的确切尺寸，所以调用者应该提供一些额外的信息，有以下三种方式：

1.使用标记制定数组长度
要求数组本身包含一个结束标记，典型是c风格字符串，**不推荐**

2.使用标准库规范
传递指向数组首元素与尾元素的指针
```
void print(const int *beg,const int *end)
{
	while(beg != end)
		//操作
}
//使用时
print(begin(xx),end(xx));
```
3.传递一个表示数组大小的形参
	
	void print(const int *beg, size_t size);

----
#### 4.initializer_list形参
如果函数的实惨数量未知但是全部实参类型相同，我们可以使用initializer_list类型的形参
initializer_list对象中的元素永远是常量值，不能改变
----
#### 5.不要返回局部对象的引用或指针
```
const string &manip()
{
	string str = "hello world";
	return str;//错误，返回局部对象的引用
	return "hello world";//错误，返回局部临时量
}
```
----
#### 6.使用尾置返回类型
为了表示函数真正的返回类型跟在形参列表之后，在本应该出现返回类型的地方放置一个auto

	auto func(int i) ->int(*) [10];
	func返回的是一个指针，并且该指针指向了含有10个整数的数组
----
#### 7.使用函数指针
```
bool (*pf)(const string &,const strin &)
//pf是一个指向返回值是bool类型，参数是2个const string &类型的指针
pf = lengthCompare;
pf = &lengthCompare;//等价的赋值语句，&是可选的选项
//将lengthCompare的地址赋给pf
bool b1 = pf(str1,str2);
bool p2 = (*pf)(str1,str2);
bool p3 = lengthCompare(str1,str2);
//以上是等价的三种调用
//我们可以直接使用指向函数的指针调用函数而不需要解引用
```
----
#### 8.函数指针形参
```
void useBigger(const string &s1,bool pf(const string &st1));
void useBigger(const string &s1,bool (*pf)(const string &st1));
//以上是等价的声明
```
类型别名和decltype可以简化使用函数指针的代码
```
typedef bool Func(const string);
typedef decltype(lengthCompare) Func2;//等价的类型
//Func与Func2是函数类型
typedef bool (*FuncP)(const string);
typedef decltype(lengthCompare) *FuncP2;//等价的类型
//FuncP与FuncP2是函数指针类型
```
----
#### 9.类中的const变量初始化只能使用列表初始化

	Book():isbn(isbn)
	{}
----
#### 10.类成员的初始化顺序只与它们在类定义中出现的顺序一致，与构造函数初始值列表中初始值的前后位置关系不会影响实际的初始化顺序。
----
#### 11.隐式的类类型转换
```
Sales_data中构造函数有Sales_data(String &)的就可以在需要该类的地方用string替换
string null_look;
items.combine(null_look);
null_look会转换为一个临时的Sales_data对象;
这种转换只能发生一次,
items.combine("123");就是不行的，
“123”转换成了string再转换成Sales_data
```
抑制转换就在相应的构造函数之前加explicit
----
### 301页c++primer

