### 1.函数模板
模板定义以关键字**template**开始，后跟一个模板参数列表，用逗号分隔一个或多个模板参数的列表，用小于号和大于号包围起来。
```
template <typename T>
int compare(const T &v1,const T &v2);
```
类型参数前必须使用关键字class或typename
#### 除了定义类型参数还可以定义非类型参数
一个非类型参数表示一个值而非一个类型，通过一个特定的类型名来指定非类型参数。
```
template<unsigned N, unsigned M>
int compare(const char (&sp1)[N], const char (&sp2)[M]);
```
*函数模板和类模板成员函数的定义通常放在头文件中*
#### 类模板
类模板与函数模板有些相似都是以template开始后接模板参数列表
```
template <typename T> class Blob{ }
```
#### 参数包
```
template<typename T, tyoename... Args>
ostream &print(ostream &os,const T &t,const Args&... rest);
```

----
### 2.tuple类型
不同tuple类型的成员类型不相同，一个tuple可以有任意数量的成员，每个确定的tuple类型的成员数是固定的，但一个tuple类型的成员数目可以与另一个tuple类型不同。
```
tuple<T1,T2,...,Tn> t;
t是一个tuple成员数为n，所有成员都进行值初始化
tuple<T1,T2,...,Tn> t(v1,v2,...,vn);
初始化
make_tuple(v1,v2,...,vn);
返回一个用给定初始值初始化的tuple。
t1 == t2 | t1 != t2
比较相等
t1 relop t2 
两个tuple必须具有相同的数量的成员，使用<运算符比较对应成员
get<i>(t)
返回t的第i个数据成员的引用。
tuple_size<tupleType>::value
一个类模板可以通过tuple类型来初始化，value类型为size_t，表示tuple中成员的数量
tuple_element<i,tupleType>::type
一个类模板，通过一个整型来初始化，type表示tuple类型中指定成员的类型
```
	typedef decltype(item) trans;
	size_t sz = tuple_size<trans>::value;
	tuple_element<1, trans>::type cnt = get<i>(item);
tuple可以帮助函数返回多个值

----
### 3.bitset类型
标准库还定义了bitset类，使得位运算更加容易，且能够处理超过最长整形类型大小的位集合。bitset定义在bitset头文件中

----
### 4.随机数引擎
```
default_random_engine e;
for (size_t i = 0;i < 10;++i)
	cout << e() <<" ";
```
定义了一个随机数引擎对象default_random_engine对象。
```
Engine e;//默认构造函数；
Engine e(s);//使用整形值作为种子
e.seed(s);//s重制种子
e.min();|e.max();//最小值或最大值
e.discard(u);//将引擎推进n步
```
random头文件中，engine与distribution组合起来生成随机数。

----
### 5.命名空间
命名空间结束后无需分号，每个命名空间都是一个作用域。


