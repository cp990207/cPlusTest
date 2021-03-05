/*
 *曹鹏
 *2月20日
 *学写c++primer
*/
#include<iostream>
#include<random>
using namespace std;

void rand_engine()
{
    default_random_engine e;
    cout << e.max() << endl;
    cout << e.min() << endl;
    uniform_int_distribution<unsigned> u(0,9);//int变成real，unsigned变成double之后就会变成小数
    for(size_t n = 0; n < 10; n++)
        cout << u(e) << endl;
}
int  main(int argv,char *args[])
{
    rand_engine();
}