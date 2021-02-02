/*
 *caopeng
 *2月2日
 *c++primer学习记录
 */
#include<iostream>
using namespace std;

size_t countStatic()
{
    static size_t ctr = 0;
    return ++ctr;
}
//static变量的测试

void print(const int num[6])
{
    cout << num[9] <<endl;
}
//测试数组作为参数

const string &shorterstring(const string &str1,const string &str2)
{
    return str1.size()<str2.size() ? str1 : str2;
}
string &shorterstring(string &str1,string &str2)
{
    auto &r = shorterstring(const_cast<const string &>(str1),const_cast<const string &>(str2));
    return const_cast<string &>(r);
}
//有了下面的重载函数就可以获得普通的引用，从而修改str1或st2的参数了

class Book
{
    friend size_t add(Book &,Book &);
    friend void printIsbn(Book );
public:
    Book() = default;
    Book(int num,const string &isbn):isbn(isbn)//const 变量初始化只能用列表初始化
    {
        this->bookNum = num;
    }
    Book(const string isbn):Book(11,isbn){}
private:
    int bookNum;
    const string isbn;
};
size_t add(Book &bo1,Book &bo2)
{
    return bo1.bookNum + bo2.bookNum;
}

void printIsbn(Book bo)
    {
        cout << bo.isbn << endl;
    }
//类的使用测试

int main()
{
    return 0;
}

//看到301页c++primer
