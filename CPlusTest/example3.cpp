/*
 *曹鹏
 *2021/2/1 9:40
 *c++primer 学习第三天
 */

#include<iostream>
#include<vector>
#include<cctype>
#include<stdexcept>
using namespace std;
void vectorCinTest()
{
    vector<string> strv;
    string temp;
    while( cin >> temp )
    {
        strv.push_back(temp);
    }
    for ( auto &st : strv )//引用符号不要忘记了
    {
        for ( auto &c : st )//引用符号不要忘记了
        {
            c = towupper(c);
        }
        cout << st << endl;
    }
}
//练习：cin读入一组词存入vector对象，并且将每个词都改成大些形式，输出出来，一行一个

void iterTest()
{
    string test = "hello world nice to see you!";
    if ( test.begin() != test.end() )
    {
        for ( auto btest = test.begin() ;
             btest != test.end()&&!isspace(*btest) ;//btest需要加*来解引用 不然btest表示迭代器不能进行字符判断
             ++btest )
        {
            *btest = toupper(*btest);
        }
    }
    cout << test << endl;
}
//将test第一段全部改成大写 然后再输出它

void pointerArrayTest()
{
    int target[] = {1,2,3,4,5,6,7,8};
    for ( auto n: target)
    {
        cout << n <<" ";
    }
    cout << endl;
    int *pbeg = begin(target);
    int *pend = end(target);
    while (pbeg != pend)
    {
        *pbeg = 0;
        ++pbeg;
    }
    for (auto n : target)
    {
        cout << n << " ";
    }
    cout << endl;
    
}
//利用指针将数组中元素置为0

void constToNormal()
{
    const char temp = 'c';
    const char *cp = &temp;
    char *p = const_cast<char *>(cp);
    cout << *p << endl;
    *p = 'b';
    cout << *p << endl;
}
//const_cast 测试

void excepttionTest()
{
    int a,b;
    cin >> a >> b;
    try {
        if(b == 0)
        {
            throw runtime_error("除数不能是0");//这边不能创建对象，throw一个异常就行不用加上err
        }
        cout << a/b << endl;
    } catch (runtime_error err) {
        cout << err.what() <<  endl;
    }
}
//异常处理测试
int main()
{
    //vectorCinTest();
    //iterTest();
    //pointerArrayTest();
    //constToNormal();
    //excepttionTest();
    return 0;
}
//看到第208页
