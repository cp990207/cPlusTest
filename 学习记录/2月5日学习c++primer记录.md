#### 1.可以用new返回的指针来初始化一个智能指针，接受指针参数的智能指针构造函数是explicit的，因此不能将一个内置指针隐式转化成智能指针，必须使用直接初始化形式。
```
shared_ptr<int> p1 = new(1024);//错误，隐式地初始化
shared_ptr<int> p2(new(1024));//正确，直接初始化形式
```
----
#### 2.unique_ptr不支持普通的赋值与拷贝，但是提供了release、reset等函数
```
u.release()//u放弃对指针的控制权，返回指针，并将u置为空
u.reset(q)//释放u指向的对象，令u指向q
```
----
#### 3.allocator类定义在头问价memory中，它帮助我们将内存分配和对象构造分离开来
```
allocator<string> alloc;//可以分配string的allocator对象
auto const p = alloc.allocate(n);//分配n个未初始化的string
```
allocate算法

|算法|解释|
|:----------|:----------|
| uninitialized_copy(b,e,b2)    | 拷贝迭代器b，e范围中的元素到b2指定的未构造的原始内存中去，b2指向的内存需要能容纳输入序列中元素的拷贝|
| uninitialized_copy_n(b,n,b2)    | 从迭代器b指向的元素开始，拷贝n个元素到b2开始的内存中   |
| uninitialized_fill(b,e,t)|在迭代器b，e指定的原始内存范围中创建对象，对象的值均为t的拷贝|
| uninitialized_fill_n(b,n,t)|从迭代器b指向的地址开始创建n个对象。b必须指向足够大的未构造的原始内存，能够容纳给定数量的对象|

### 看到第468页