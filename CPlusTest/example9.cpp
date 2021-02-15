/*
 *曹鹏
 *2月10日
 *c++primer学习记录
 */
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include<sstream>
#include<functional>
using namespace std;
int add(int a, int b) { return a+b; }
void calculate()
{
    map<string, function<int(int, int)> > cal_map;
    cal_map.insert({"+",add});
    cout << cal_map["+"](1,2) << endl;
}
//function的调用
class Basic{
private:
    size_t num;
public:
    Basic(int t)
    {
        if(t>=0)
            num = t;
        else
            num = -t;
    }
    size_t get_num() const
    {
        return num;
    }
    virtual void print() const;
    virtual ~Basic()
    {
        cout << "调用Basic的析构函数" << endl;
    }
};
class Extend :public Basic{
public:
    Extend(int n):Basic(n){}
    void print() const override;
    ~Extend()
    {
        cout << "调用Extend的析构函数" << endl;
    }
};
void Basic::print() const
{
    cout << "调用虚函数 " << num << endl;
}
void Extend::print() const{
    cout << "调用实函数 " << get_num() << endl;
}
void print_num(const Basic& b)
{
    b.print();
}
//虚函数与实函数测试
class QueryResult{
private:
    string findword;
    shared_ptr<set<size_t>> lines;
    shared_ptr<vector<string>> allfile;
public:
    QueryResult(const string &s, shared_ptr<set<size_t>> l, shared_ptr<vector<string>> a):
        findword(s),lines(l),allfile(a) { }
    decltype(lines -> begin())
        begin() { return lines -> begin();}
    decltype(lines -> end())
        end() { return lines -> end();}
    shared_ptr<vector<string>> get_file() { return allfile; }
    void print(ostream &os);
};
void QueryResult::print(ostream &os)
{
    auto beg = lines->begin();
    os << findword << "出现了：" << lines -> size() << "次:" << endl;
    while(beg != lines -> end()){
        os << "( line: " << *beg << ") " << (*allfile)[(*beg)-1] << endl;
        ++beg;
    }
    
}
class TextQuery{
public:
    using line_no = set<size_t>;
    TextQuery(istream &);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> allfile;
    map<const string,shared_ptr<line_no>> ma;
};
TextQuery::TextQuery(istream &is):allfile(new vector<string>){
    string temp;
    size_t line = 1;
    while(getline(is,temp)){
        allfile -> push_back(temp);
        istringstream ist(temp);
        string word;
        while(ist >> word)
        {
            auto &lines = ma[word];
            if(!lines)
            {
                lines.reset(new line_no);
            }
            lines -> insert(line);
        }
        ++line;
    }
}
QueryResult TextQuery::query(const string &s) const
{
    static shared_ptr<set<size_t>>no_find(new set<size_t>);
    auto result = ma.find(s);
    if(result != ma.end())
    {
        return QueryResult(s,result -> second,allfile);
    }
    return QueryResult(s,no_find,allfile);
}
class Query_base{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &,const Query &);
    friend Query operator|(const Query &,const Query &);
public:
    Query(const string &);
    QueryResult eval(const TextQuery &t) const{
        return q->eval(t);
    }
    string rep() const{
        return q->rep();
    }
private:
    Query(shared_ptr<Query_base> query):q(query) {}
    shared_ptr<Query_base> q;
};
ostream &operator<<(ostream &os, const Query &query)
{
    return os << query.rep() << endl;

}

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const string &s) : query_word(s) {}
    QueryResult eval(const TextQuery &t) const{
        return t.query(query_word);
    }
    string rep() const { return query_word; }
    string query_word;
};

Query::Query(const string &s) : q(new WordQuery(s)) { }

class NotQuery : public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q) { }
    string rep() const { return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const;
    Query query;
};
Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, string s):lhs(l),rhs(r),opSym(s) { }
    string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs,rhs;
    string opSym;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &left,const Query &right):
        BinaryQuery(left,right,"&") { }
    QueryResult eval(const TextQuery&) const;
};
Query operator&(const Query &lhs,const Query &rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left,const Query &right):
        BinaryQuery(left,right,"|") { }
    QueryResult eval(const TextQuery&) const;
};
Query operator|(const Query &lhs,const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const{
    auto right = rhs.eval(text),left = lhs.eval(text);
    auto ret_lines =
        make_shared<line_no>(left.begin(),left.end());
    ret_lines -> insert(right.begin(), right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const{
    auto left = lhs.eval(text),right = rhs.eval(text);
    auto ret_lines = make_shared<line_no>();

    /*auto leftb = left.begin();
    while(leftb != left.end())
    {
        if(right.find(*leftb))
            ret_lines -> insert(*leftb);
        ++leftb;
    }*/
    //求出两个范围的交集，再写入ret_lines

    //利用标准库，求出两个范围的交集，写入ret_lines
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),
                     inserter(*ret_lines,ret_lines -> begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const{
    auto result = query.eval(text);
    auto ret_lines = make_shared<line_no>();
    auto beg = result.begin(),end = result.end();
    auto sz = result.get_file() -> size();
    for(size_t n; n!=sz; ++n)
    {
        if(beg==end || *beg!=n)
            ret_lines -> insert(n);
        else if(beg!=end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
int main(int argv,char *args[])
{
    //calculate();
    /*Basic b(10);
    Extend e(-20);
    print_num(b);
    print_num(e);*/
    ifstream ifs("1.txt");
    TextQuery text(ifs);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    cout << q.rep() << endl;
    q.eval(text).print(cout);

}