#### 1.消除重复算法
sort排序，unique将重复的单词放到最后，erase删除最后重复的单词
```
sort(words.begin(),words.end());
auto end_unique = unique(words.begin(),words.end());
erase(end_unique,words.end());
```
----
#### 2.定制操作：向算法传递函数
重载sort函数，增加第三个参数--谓词
	
	sort(words.begin(),words.end(),isShorter);
	isShorter是一个返回bool的含两个参数的函数
	stable_sort维持相等元素的原有顺序
----
#### 3.lambda表达式
[capature list](parameter list) -> return type {body}
capature list:捕获列表，是表达式所在函数中定义的局部变量的列表，通常为空
parameter list:参数列表
return type:返回类型
body:函数体
可以忽略参数列表与返回类型，但必须包含捕获列表与函数体

	auto f = [] {//函数体};


可变lambda，如果我们希望能够改变一个被捕获的变量的值，就必须在参数列表首加上关键字mutable
```
size_t v1 = 42;
auto f = [v1]{return ++v1;}
v1 = 0;
cout << f << endl;
//输出的是43
```

----
#### 4.for_each算法
```
for_each(wc, words.end(), [](string &str)
							{ cout << str << " "; });
//wc迭代器到words.end()之间每个单词，单词之间空一格
cout << endl;
```
----
#### 5.标准库bind函数!!!
定义在头文件functional中，可以将bind函数看作一个通用的函数适配器，接受一个可调用对象，生成一个新的可调用用对象来适应

	auto newCallable = bind(callable, arg_list);
----
#### 6.插入迭代器
```
back_inserter创建一个使用push_back的迭代器
front_inserter使用一个push_front的迭代器
inserter创建一个使用insert的迭代器，接受的第二个参数必须是一个
指向给定容器的迭代器，元素将被插入到给定迭代器所指定的元素之前
```
----
#### 7.关联容器
map与set
map中的元素 ：关键字-值
set中每个元素都值包含一个关键字
map与multimap定义在头文件map中；set与multiset定义在头文件set中，无序容器set定义在头文件unordered_set中，无序容器map定义在unordered_map中

使用map
```
map<string,size_t> word_count;//string到size_t的空map
string word;
while( cin >> word )
	++word_count[word];
for( const auto &w : word_count )
{
	cout << w.first << "出现了" << w.second << "次" << endl;
}
```
迭代器用的是->,map元素用的是.
使用set
```
set<string> setStr = {"hello","world"};
```
----
#### 8.pair类型，定义在头文件utility中。
map的元素是pair

----
#### 9.insert的返回值：对于不包含重复关键字的容器，添加单一元素的insert和emplace版本返回一个pair，告诉我们插入是否成功。pair的first成员是一个迭代器，指向具有给定关键字的元素；second成员是一个bool值，成功为true，失败为false。
----
#### 10.动态内存与智能指针
new，在动态内存中为对象分配空间并返回一个指向该对象的指针；
delete，接受一个动态对象的指针，销毁该对象，并释放与之有关的内存
```
为了更安全地使用动态内存，新标准库提供了两种智能指针：
shared_ptr:允许多个执政指向同一对象
unique_ptr:独占所指向的对象
weak_ptr:一种弱引用，指向shared_ptr所管理的对象
三种类型都定义在memory头文件中
```

### 看到第430页