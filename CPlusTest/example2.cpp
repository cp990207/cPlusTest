//
//  example2.cpp
//  CPlusTest
//
//  Created by  曹鹏 on 2021/1/31.
//

#include<iostream>
using namespace std;

void quotoTestOne()
{
    int i , &ri = i;
    i=10;
    ri=11;
    cout << i << " " << ri << endl;
}
//测试引用的赋值
int main()
{
    quotoTestOne();
    return 0;
}
