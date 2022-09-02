# UNION那些事

## 关于作者：

个人公众号：

![](../img/wechat.jpg)

联合（union）是一种节省空间的特殊的类，一个 union 可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。当某个成员被赋值后其他成员变为未定义状态。联合有如下特点：

- 默认访问控制符为 public
- 可以含有构造函数、析构函数
- 不能含有引用类型的成员
- 不能继承自其他类，不能作为基类
- 不能含有虚函数
- 匿名 union 在定义所在作用域可直接访问 union 成员
- 匿名 union 不能包含 protected 成员或 private 成员
- 全局匿名联合必须是静态（static）的
下面是一些补充说明
"""cpp
#include <iostream>
using namespace std;
struct Student {
	int age;
	int score;
	Student(int a,int s) {
		age=a;
		score=s;
	}
};

union testunion {
	char c;
	int i;
};

class someClass {
	int num;
public:
	void show(){cout<<num<<endl;}
};

union A {
	char c;
	int i;
	double d;
	someClass s;
};

union B {
	char c;
	int i;
	double d;
	B(){d=8.9;}
};

union {
	char c;
	int i;
	double d;
	void show(){cout<<c<<endl;}
} u = {'U'};

int main(int argc,char* argv[]) {
	A a={'A'};
	B b;
	cout<<a.c<<endl;
	cout<<b.d<<endl;
	a.s.show();
	u.show();
	
	// 匿名共用体。
	union {
		int p;
		int q;
	};

	p=3;
	cout<<q<<endl;
}

"""
- union 可以指定成员的访问权限，默认情况下，与 struct 具有一样的权限（public）
