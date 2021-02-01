#### 1.迭代器
获取迭代器是通过拥有迭代器的类型中返回迭代器的成员begin与end
```
v.begin();//获取的是指向第一个元素的迭代器
v.end();//获取的是指向尾元素下一个位置的迭代器

*iter//返回迭代器所指元素的引用
```

----
#### 2.数组的类型必须要制定，所以不允许用auto关键字初始化数组。数组元素应为对象，不存在引用的数组。
----
#### 3.标准库函数begin与end
	begin(a);//返回指向a首元素的指针
	end(a);//返回指向a尾元素下一位置的指针
----
#### 4.c_str函数返回值是一个c风格字符串。函数返回的是一个指针，该指针指向一个以空字符结束的字符数组
----
#### 5.要使用for处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型。
```
for ( auto &n : arry)
	for( auto col : n)
		//statement
```
----
#### 6.命名强制类型转换csat-name<type>(expression);
	cast-name是static_cast、dynamic_cast、const_cast
	与reinterpret_cast

	static_cast只要不包含底层const,都可以使用static_cast
	double num = static_cast<double>(j);
	可以找回存于void指针中的值
	double *dp = static_cast<double *>(j);

	dynamic_cast支持运行时类型识别
	
	const_cast只能改变运算对象的底层const，将常量转化为非常量的行为，
	如果对象本身不是一个常量那么是合法的，如果对象本身就是一个常量，强制类型转换后
	执行写操作会出现为定义的后果。一般用于函数重载的上下文中。

	reinterpret_cast为运算对象的位模式提供较低层次上的重新解释(比较危险，不推荐使用）
	int *ch;
	char *cha = reinterpret_cast<char>(ch);
----
#### 7.标准异常
exception头文件定义了最通用异常类exception；只报告异常发生，不提供额外信息
stdexcept头文件定义了几种异常类型

| 名称  | 解释  |
|:----------|:----------|
| exception    | 最常见的问题    |
| runtime_error    | 只有运行时才能检测出的问题    |
| range_error    | 运行时错误：生成的结果超出了有意义的值域范围    |
| overflow_error    | 运行时错误：计算上溢    |
| underflow_error    | 运行时错误：计算下溢    |
| logic_error    | 程序逻辑错误    |
| domain_error    | 逻辑错误：参数对应的结果值不存在    |
| invalid_argument    | 逻辑错误：无效参数    |
| length_error    | 逻辑错误：试图创建一个超出该类型最大长度的对象    |
| out_of_range    | 使用一个超出有效范围的值    |
----
### 看到第208页

	