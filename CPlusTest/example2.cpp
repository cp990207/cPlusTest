//
//  example2.cpp
//  CPlusTest
//
//  Created by  曹鹏 on 2021/1/31.
//

#include<iostream>
#include<cctype>
#include<vector>
using namespace std;

void quotoTestOne()
{
    int i , &ri = i;
    i=10;
    ri=11;
    cout << i << " " << ri << endl;
}
//测试引用的赋值 ri与i是等价的 改ri就是改i

void pointerBool()
{
    int point = 0;
    int *pointOther = &point;
    if (pointOther)
    {
        cout << "pointOther表示真" << endl;
    }
}
//测试指针作为bool的关系 空指针被判断为false，有地址的指针被判断为true

class Sale
{
public:
    string str = "hello world!";
};
//与Java不一样Scale sale 就已经为sale创建对象了，new Sale（）;返回的将是Sale的指针

void readStringTest()
{
    string str;
    while (getline(cin,str))
    {
        cout << str << endl;
    }
    cout << "以上是getline的读取测试" << endl;
    while (cin>>str)
    {
        cout << str <<endl;
    }
    cout<< "以上是cin的读取测试" << endl;
}
//试验读取字符串的两种方式

void stringAddTest()
{
    // string str1 = "hello " + "wolrd"; 不能两个字符串常量值相加
    string str1 = "hello ";
    string str2 = "world";
    string str3 = str1 + "world";
    //每个加法运算符两侧至少有一个是string对象
    cout << str3 << endl;
}
//测试字符串想相加

void forAndStringTest()
{
    cout << "请输入一个字符串，可以带空格，以enter结束" << endl;
    string str1;
    string str2;
    getline(cin,str1);
    for( auto c : str1)
    {
        if(isgraph(c))
        {
            str2 += c;
        }
    }
    cout << "去掉空格之后的字符串为：" << str2 << endl;
}
//范围for与string的测试

void vectorTest()
{
    vector<int> numv ={1,2,3,4,5};
    for (auto &n : numv) //只有加上&作为引用才可以修改numv中的值
    {
        n *= n;
    }
    for (auto n : numv)
    {
        cout << n << endl;
    }
}
//vector的遍历测试
int main()
{
    //quotoTestOne();
    //pointerBool();
    //readStringTest();
    //stringAddTest();
    //forAndStringTest();
    //vectorTest();
    return 0;
}

//<<c++primer>>看到120页
