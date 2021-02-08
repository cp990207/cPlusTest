/*
 *曹鹏
 *2月6日
 *c++primer学习记录
 */
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<utility>
using namespace std;
class Numered{
public:
    size_t mysn;
    Numered()
    {
        mysn = rand();
    }
    Numered(Numered &n)
    {
        mysn = rand();
    }
};
void f(const Numered &s) { cout << s.mysn << endl;}

class Employee{
public:
    string name;
    static int no;
    Employee(string name)
    {
        this->name = name;
        this->no = 0;
        ++no;
    }
    Employee(Employee &e)
    {
        this->name = e.name;
        ++no;
    }
};
int Employee::no =0;

void moveAfterTest()
{
    int i = 42;
    cout << i << endl;
    int &&r = move(i);
    cout << i << " " << r << endl;//最好不要使用移后源，但是使用目前没有什么报错
    i = 34;
    cout << i << " " << r << endl;
}

class String{
public:
    String(String &s)
    {
        str = new(char[strlen(s.str)+1]);
        strcpy(str,s.str);
    }
    String &operator=(String &s)
    {
        str = new(char[strlen(s.str)+1]);
        strcpy(str,s.str);
        return *this;
    }
    String(String &&s):str(s.str)
    {
        cout << str << "调用移动赋值运算符" << endl;
        s.str = nullptr;
    }
    String &operator=(String &&s)
    {
        str = s.str;
        s.str = nullptr;
        cout << str << "调用移动构造函数" << endl;
        return *this;
    }
    String(char *str = "")
    {
        this->str = new(char[strlen(str)+1]);
        strcpy(this->str,str);
    }
    void show()
    {
        cout << str << endl;
    }
    friend ostream &operator<<(ostream &,const String &);
private:
    char *str;
};
ostream &operator<<(ostream &os,const String &s)
{
    os << s.str;
    return os;
}
//String测试移动构造函数以及移动复制运算符
int main(int argv,char *args[])
{
    //moveAfterTest();
    /*srand(time(NULL));
    Numered a,b = a,c = b;
    f(a);f(b);f(c);*/
    /*Employee first("hello"),second(first);
    cout << first.name << " " << first.no << endl;
    cout << second.name << " " << second.no << endl;*/
    /*String str("hello world");
    String str2(move(str));
    String str3 = move(str2);
    cout << str3 << endl;*/
}
