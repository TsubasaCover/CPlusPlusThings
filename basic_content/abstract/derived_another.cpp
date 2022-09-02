/**
 * @file derived_another.cpp
 * @brief 完整示例！定义抽象类的指针指向继承类！
 * @author wilsonsteven
 * @version v1
 * @date 2022-09-2
 */

#include<iostream>
using namespace std;

class Base
{
public:
    Base(){
        cout<<"call base contruct"<<endl;
    }
    virtual~Base(){
        cout<<"call base destruct"<<endl;
    }
    int x;
    virtual void fun() = 0;
    int getX() { return x; }
};

class Derived: public Base
{
public:
    Derived(){
        cout<<"call Derived contruct"<<endl;
    }
    ~Derived(){
        cout<<"call Derived destruct"<<endl;
    }

    int y;
    void fun() { cout << "fun() called" << endl; }  // 实现了fun()函数
};

int main(void)
{
    Base *d = new Derived;
    d->fun();
    delete d;
    return 0;
}
