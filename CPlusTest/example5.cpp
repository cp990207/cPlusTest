/*
 *曹鹏
 *2月3日
 *学习c++primer记录
 */
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<numeric>
#include<algorithm>
#include<fstream>
using namespace std;

istream &istreamTest(istream &is)
{
    while (!is.eof())
    {
        string str;
        is >> str;
        cout << str << endl;
    }
    is.clear(ios::goodbit);
    return is;
}
//从给定流中读取数据，知道遇见文件结束符时停止，将读取的数据打印在标准输出上，对流进行复位，使其处于有效状态
//strm::貌似找不到这个定义

void fstreamTest(const string &s1)
{
    ifstream ifp(s1);
    vector<string> vec;
    if(ifp)
    {
        string temp;
        while(!ifp.eof())
        {
            getline(ifp,temp);
            vec.push_back(temp);
        }
        ifp.close();
    }
    for (auto vecn : vec)
        cout << vecn << endl;
    ofstream ofp(s1,ofstream::app);
    if(ofp)
    {
        ofp << "welcome to the computer world" << endl;
        ofp.close();
    }
}
//文件读写的测试

vector<int>::iterator iteratorTest(vector<int>::iterator vbegin,
                  vector<int>::iterator vend,
                  int lookup)
{
    while(vbegin != vend)
    {
        if(*vbegin == lookup)
        {
            return vbegin;
        }
        ++vbegin;
    }
    return vend;
}
//vector的迭代器的测试

void queueTest()
{
    deque<int> deq{1,2,3,4,5,6,7,8};
    queue<int> que(deq);
    cout << que.front() << que.back() << endl;
    que.pop();
    cout << que.front() << que.back() << endl;
    
}
//队列操作的测试

void accumulateTest()
{
    vector<double> vec {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    auto sum = accumulate(vec.cbegin(),vec.cend(),0);
    cout << sum << endl;
}
//acculumate泛型求和函数测试

void equalTest()
{
    char str1[]{'H','e','l','l','o'};
    char str2[]{'H','e','l','l','o'};
    vector<char *> vec1{str1,"world"};
    vector<char *> vec2{str2,"world","welcome","c++"};
    cout << equal(vec1.cbegin(),vec1.cend(),vec2.cbegin()) << endl;
}
//equal泛型比较是否相等元素测试
int main(int argv,char *args[])
{
    //cout << (istreamTest(cin)).eof() << endl;
    //fstreamTest("1.txt");
    /*
    vector<int> vec {1,2,3,4,5,6,7};
    if(iteratorTest(vec.begin(),vec.end(),10)!=vec.end())
        cout << *iteratorTest(vec.begin(),vec.end(),5) <<endl;
    else
        cout << "没有找到！" << endl;
     */
    //queueTest();
    //accumulateTest();
    //equalTest();
    return 0;
}
//看到第368页
