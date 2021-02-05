/*
 *caopeng
 *2月5日
 *c++primer学习感悟
 */
#include<iostream>
#include<fstream>
#include<sstream>
#include<set>
#include<map>
#include<vector>
using namespace std;
int *numO;
shared_ptr<int> sharedPtrTest()
{
    int *num = new int(12);
    numO = num;
    cout << *numO << endl;
    auto number = shared_ptr<int>(num);
    return number;
}
//智能指针的测试

class ShowResult
{
    friend void print(ostream &,const ShowResult &);
public:
    ShowResult(string &w,shared_ptr<set<size_t>> l,shared_ptr<vector<string>> a):
    word(w),lines(l),alltexts(a){}
private:
    shared_ptr<vector<string>> alltexts;
    shared_ptr<set<size_t>> lines;
    string word;
};

class TextFind
{
public:
    TextFind(ifstream &ifs):alltexts(new vector<string>),results(new map<string,shared_ptr<set<size_t>>>)
    {
        string line;
        while(getline(ifs,line))
        {
            alltexts -> push_back(line);
            string word;
            istringstream ist(line);
            while(ist >> word)
            {
                auto &lineSet = (*results)[word];//前面要加上&
                if(!lineSet)
                {
                    lineSet.reset(new set<size_t>);
                }
                lineSet->insert(alltexts->size()-1);
            }
        }
    }
    
    ShowResult find(string &word) const
    {
        static shared_ptr<set<size_t>> noFind(new set<size_t>);
        auto rword = results->find(word);
        if(rword == results->end())
            return ShowResult(word,noFind,alltexts);
        return ShowResult(word,rword->second,alltexts);
    }
private:
    shared_ptr<vector<string>> alltexts;
    shared_ptr<map<string,shared_ptr<set<size_t>>>> results;
};

void print(ostream &os,const ShowResult &sr)
{
    os << sr.word << "在文中出现了" << sr.lines->size() << "次：" << endl;
    for(auto li : (*sr.lines))
    {
        os << "line:" << li+1 << " " << (*sr.alltexts)[li] << endl;
    }
}

class Client
{
public:
    Client(ifstream &file)
    {
        TextFind tf(file);
        cout << "请输入要查询的单词，按q退出" << endl;
        while(true)
        {
            string word;
            if( !(cin >> word) || word == "q") break;
            print(cout, tf.find(word));
        }
    }
};
//一个利用map，set，shared_ptr写的查找单词出现次数以及未知的模块，为了足够抽象分为三个类
int main(int argv,char *args[])
{
    /*ifstream ifs("example5.cpp");
    new Client(ifs);*/
    //cout << *(sharedPtrTest()) << endl;
    
}
