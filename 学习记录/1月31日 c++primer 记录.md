#### 1.引用就是为对象起另外一个名字，通过将声明符写成&d的形式来定义引用类型。
	程序将引用和它的初值绑定在一起，并且无法替换，因此引用必须要初始化
	引用必须绑定在对象上，不能绑定在字面值或者运算结果上
----
#### 2.的到空指针最直接的办法就是用字面值nullptr来初始化指针
---
#### 3.指针在使用之前一定要给他赋予一个地址
```
int *num;
*num = 0;
//会报错，因为没有给指针赋值，相当于没有空间

int *num;
int temp;
num = &temp;
*num = 0;
//不会报错因为给了指针赋值了
```
----
#### 4.int *num = 0;表示初始化num为一个空指针;不可以给int *num赋除了0以外的其他数，因为指针不能赋int类型，0指代空指针其他没有指代。
----
#### 5.int *p1,p2;表示int类型的p1指针与int类型的p2；*仅修饰紧贴的一个。
----
#### 6.const对象一旦创建后其值就不能改变，所以必须初始化。
----
#### 7.对常量的引用不能用作修改它所绑定的对象
	const int cnum = 1;
	const int &cnumy = cnum;//正确
	int &numy = cnum;//错误不能让一个非常量引用绑定一个常量
----
#### 8.auto类型说明符可以让编译器替我们去分析表达式所属类型，auto定义的变量必须有初值。与const相关的有些不清晰；
```
auto item = var1 + var2;//由var1与var2相加的结果推算出item的类型
```
----
#### 9.decltype选择并返回操作数的数据类型。与引用有关的有些不清晰；
```
decltype(f()) sum = x;//sum类型就是f返回值类型
```
----
#### 10.头文件保护符
```
#ifdef当且仅当变量以定义时为真
#ifndef当且仅当变量未定义时为真
#endif当未真时执行到这里为止

#ifndef Sale
#define Sale
#inclde<string>
class Sale
{
	string str = "hello world";
}
#endif
```
----
#### 11.定义class或者struct在作用域最后要加上分号
```
class xxx{
	xxx
};
```
----
#### 12.读取未知数量的字符串对象，cin读到空格、换行符、制表符停止，getline一次读一行保留输入时的空白符
----
#### 13.不能两个字符串常量值相加，加号左右至少有一个是string对象
```
	string str1 = "hello ";
    string str2 = "world";
    string str3 = str1 + "world";
```
----
#### 14.cctype头文件中包含处理字符的一些操作
----
#### 15.vector对象 
	使用vector对象需要包含头文件#includez<vector>
	vector中的成员函数push_back向其添加元素
	for( auto &n : vec)才能修改vec中的值，直接赋值不能修改

### <<c++primer>> 看到第120页