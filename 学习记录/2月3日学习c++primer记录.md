#### 1.IO库类型和头文件
| 头文件  | IO库类型  |
|:----------|:----------|
| iostream   | istream,wistream  从流读取数据 |
|    | ostream,wostream 向流写入数据    |
|     | iostream,wiostream 读写流    |
| fstream    | ifstream,wifstream从文件读取数据  |
|     | ofstream,wofstream向文件写入数据 |
|    | fstream,wfstream读写文件|
| sstream   | istringstream,wistringstream 从string读取数据    |
|     | ostringstream,wostringstream 向string写入数据    |
|     | stringstream,wstringstream 读写string   |
----
#### 2.IO的条件状态
```
s.eof() //若为eofbit的位置则返回true 
s.fail()//若为failbit或badbit的位置则返回true
s.bad()//若为badbit的位置则返回true
s.good()//若为有效状态怎返回true
s.clear()//将s中条件状态位置复位，将流的状态设置为有效，返回void
s.clear(flags)//根据falgs复位s中的条件状态位置，flags的状态为：strm::iostate
s.setstate(flags)//根据flags将s设置为对应的状态位置，flags的状态为：strm::iostate
s.rdstate()//返回s当前条件状态，返回类型为：strm::iostate
```

如果想要使用eofbit等strm::iostate可以用cin.eofbit等iostream对象或者ios::eofbit

setstate 不强制覆盖状态 如果原来eof，那没就算setstate(ios::good)还是eof  
clear 强制覆盖状态，后面是什么状态就只变成这个状态

----
#### 3.cout << unitbuf所有输出操作后都会立即刷新缓冲区;cout << nounitbuf回到正常的缓冲方式
----
#### 4.顺序容器类型
```
vector可变大小数组
deque双端队列
list双向链表
forward_list单向链表
array固定大小数组
string字符串
```
----
#### 5.添加删除元素（不适用于array）
```
c.insert(args)//将args中的元素拷贝进c
c.emplace(inits)//使用inits构造c中的一个元素
c.erase(args)//删除args指定的元素
c.clear()//删除c中所有的元素，返回void
```
----
#### 6.反向容器的额外成员（不支持forward_list)
```
reverse_iterator//按逆序寻址的迭代器
const_reverse_iterator//不能修改的逆序迭代器
c.rbegin()c.rend()//返回指向c首元素之前和尾元素的迭代器
c.crbegin()c.crend()//const类型
```
----
#### 7.标准库array具有固定大小，定义一个array时除了制定容器类型还要指定容器大小
	array<int,10>
----
#### 8.capacity是在不重新分配内存的前提下最多能存储多少元素，size是指它已经保存的元素的数目
----
#### 9.容器适配器
三个顺序容器适配器stack，queue，priority_queue.
一个容器适配器接受一种已有的容器类型，使其行为看起来像一种不同的类型
```
//定义一种容器适配器
//两种构造函数，默认构造函数创建一个空对象，接受一个容器的构造函数拷贝该容器来初始化适配器
deque<int> deq;
stack<int> sta(deq);
队列的pop函数是用来推出队列头元素的，删除头元素并且返回值是void
```
----
#### 10.大多数泛型算法都定义在algorithm中，标准库还在头文件numeric中定义了一组数值泛型算法
----
#### 11.插入迭代器back_inserter,定义在头文件iterator中的一个函数，一个与赋值号右侧值相等的元素被添加到容器中
```
vector<int> vec;
auto it = back_inserter(vec)
*it = 11;
//空vec经过back_inserter之后有一个元素11
//常常使用back_inserter来创建一个迭代器，作为算法的目的位置来使用
vector<int> vec;
fill_n(back_inserter(vec),10,0);
//添加10个0到vec元素中去
```
----
#### 12.copy拷贝算法，接受三个迭代器，传递给copy的目的序列至少包含与输入序列一样多的元素
```
int a1[] = {1,2,3,4,5,6,7,8,9};
int a2[sizeof(a1)/sizeof(*a1)];
auto ret = copy(begin(a1),end(a1),a2);
返回值是目的位置迭代器之后的值，ret恰好指向拷贝到a2的尾元素之后的位置
```
看到第368页
