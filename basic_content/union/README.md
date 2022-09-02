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
```cpp
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

```
- union 可以指定成员的访问权限，默认情况下，与 struct 具有一样的权限（public)
- union 也可以定义成员函数，包括构造函数和析构函数。与struct不同的是，它不能作为基类被继承。
- union 不能拥有静态数据成员或引用成员，因为静态数据成员实际上并不是共用体的数据成员，它无法和共用体的其它数据成员共享空间。对于引用变量，引用本质上是一个指针常量，它的值一旦初始化就不允许修改。如果共用体有引用成员，那么共用体对象一创建初始化后就无法修改，只能作为一个普通的引用使用，这就失去了共用体存在的意义。
- union 允许其他类的对象成为自己的数据成员，但是要求该类对象所属类不能定义 constructor，copy constructor，destructor，assignment operator，virtual function 中的任意一个。这是因为：1、union 数据成员共享内存，union构造函数在执行的时候，不能调用数据成员为类对象的构造函数，否则就改变了其他数据成员的值。2、同样，union 的对象成员的析构函数也不能被调用，因为其他数据成员的值对于对象成员而言可能毫无意义。3、union 的对象成员的赋值应该维持其原始语义，不建议进行赋值运算符的重载，因为赋值运算符重载一般用于“深拷贝”等场合，而在对象空间与其它变量共享的情况下，“深拷贝”引入的内存资源，指向内存资源的指针往往会被其它共用体数据成员修改，导致内存资源无法寻址，造成内存泄漏。此外，因为 union 的对象成员没有自定义的析构函数，也会导致内存泄漏。4、拥有虚函数的类对象，虚函数表指针可能会在共用体对象初始化时被覆盖，导致无法寻址虚函数表，所以也不能拥有虚函数。5、如果 union 类型旨在定义该类的同时使用一次，以后不再使用了，那么也可以不给出 union 的名称。如上例中变量 u 就是这种情况。这种情况下，无法为该 union 定义构造函数。
- 
