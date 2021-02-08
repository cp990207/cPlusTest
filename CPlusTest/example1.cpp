//
//  example1.cpp
//  CPlusTest
//
//  Created by  曹鹏 on 2021/1/26.
//

#include <iostream>
using namespace std;

void sayHelloWrld()
{
    cout << "Hello World" << endl;
}
//练习1 编写程序，在标准输出上打印Hello World

void  multiply()
{
    cout << "请输入你想要相乘的两个数" << endl;
    int v1 , v2;
    cin >> v1 >> v2;
    cout << v1 << " 与 " << v2 << " 相乘的结果是 " << v1*v2 << endl;
}
//练习2 使用乘法运算符打印两个数的积

void sumUnsureNum()
{
    cout << "请输入你想进行相加的数：" << endl;
    int value = 0 , sum = 0;
    while (cin >> value) {
        sum += value;
    }
    cout << "所得的和是： " << sum << endl;
}
//处理不确定数量的读取，当输入完成后可以按command+D来表示输入文件结束符，
//这样接下来按回车键就可以表示输入完成

int main(int argc, const char * argv[]) {
    //sayHelloWrld();
    //multiply();
    //sumUnsureNum();
    
    return 0;
}
