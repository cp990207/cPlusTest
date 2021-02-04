/*
 *曹鹏
 *2月4日
 *c++primer学习记录
 */
#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;
bool isShorter(const string &str1,const string &str2)
{
    return str1.size()<str2.size();
}
void sortTest()
{
    vector<string> vec {"hello","world","world","nice","to","to","see","you"};
    for (auto str : vec)
        cout << str << " ";
    cout << endl;
    sort(vec.begin(),vec.end());
    for (auto str : vec)
        cout << str << " ";
    cout << endl;
    auto unique_end = unique(vec.begin(),vec.end());
    for (auto str : vec)
        cout << str << " ";
    cout << endl;
    vec.erase(unique_end,vec.end());
    for (auto str : vec)
        cout << str << " ";
    cout << endl;
    sort(vec.begin(),vec.end(),isShorter);
    for (auto str : vec)
        cout << str << " ";
    cout << endl;
}
//对sort进行的一次测试
void lambdaTest()
{
    vector<string> vec {"hello","world","nicetoseeyou","welcome","to","c++"};
    int sz = 10;
    auto fd = find_if(vec.begin(),vec.end(),
                      [sz](string str)
                      {return str.size()>sz;});
    cout << vec.end() - fd << "距离结尾" << endl;
}
//对lambda表达式的一次尝试

void mapTest()
{
    map<string,string> ma = {{"caopeng","nice"},{"ztfn","good"}};
    for ( auto m : ma )
    {
        cout << m.first << " " << m.second << endl;
    }
    auto mab = ma.begin();
    while (mab != ma.end()) {
        mab -> second = "very " + mab -> second;
        ++mab;
    }
    for ( auto m : ma )
    {
        cout << m.first << " " << m.second << endl;
    }
}
//map的一次测试

void countWord()
{
    map<string,size_t> wordCount;
    string word;
    while(cin >> word)
    {
        auto temp = wordCount.insert({word,1});
        if(!temp.second)
        {
            ++temp.first -> second;
        }
    }
    for ( auto w : wordCount )
    {
        cout << w.first << " " << w.second << endl;
    }
}
//利用insert重写单词计数

map<string,string> buildMap(ifstream &rule)
{
    map<string,string> ru;
    if(rule)
    {
        string keyvalue;
        string value;
        try{
            while(rule >> keyvalue && getline(rule,value))
            {
                if(value.size() > 1)//检查这个规则是否存在
                    ru.insert({keyvalue,value.substr(1)});
                else
                    throw runtime_error("没有"+keyvalue+"的规则");
            }
        }catch(runtime_error err)
        {
            cout << err.what() << endl;
        }
    }
    return ru;
}

string transform(map<string,string> ma,string input)
{
    auto temp = ma.find(input);
    if(temp != ma.end())
    {
        return temp -> second;
    }
    return input;
}
void buildTransform(ifstream &rule,ifstream &input)
{
    auto ru = buildMap(rule);
    string words;
    while(getline(input,words))
    {
        istringstream ist(words);
        string word;
        bool firstword = true;
        while(ist >> word)
        {
            if(firstword)
            {
                //共有的操作最好提取出来
                firstword = false;
            }
            else
                cout << " ";
            cout << transform(ru,word);//提取的操作
        }
        cout << endl;
    }
}
//利用map，fstream，sstream写成的单词转义工具
int main(int argv ,char *args[])
{
    //sortTest();
    //lambdaTest();
    //mapTest();
    //countWord();
    /*ifstream st("rule.txt");
    ifstream ip("target.txt");
    buildTransform(st,ip);*/
    return 0;
}
