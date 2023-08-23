#include <iostream>
using namespace std;


//虚函数的重写细节
// 1.派生类的重写虚函数可以不加virtual --（建议都加）
//	 要求三同函数名，返回值，参数列表相同、
// 2.协变返回值可以不同，但是要求返回值必须是父子关系指针和引用
//
//class Person {
//public:
//	virtual void BuyTicket() const{ cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() const{ cout << "买票-半价" << endl; }
	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
	这样使用*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
// 多态的条件
// 1.调用函数重写虚函数
// 2.基类指针或者引用
// 
// 多态，不同的对象调用过去，调用不同函数
// 多态调用看指向的对象
// 普通对象，看的是当前调用类型
//
//void Func(const Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Func(Person());
//	Func(Student());
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }

	~Student() {
		cout << "~Student()" << endl;
		delete[] ptr;
	}

protected:
	int* ptr = new int[10];
};

// 析构函数可以是虚函数吗？为什么需要是虚函数？
// 析构函数加virtual，是不是虚函数重写？
// 是，因为类析构函数都被处理成destructor这个统一的名字
// 为什么要这么处理呢？因为要让他们构成重写
// 那为什么要让他们构成重写呢？
// 因为下面的场景

int main()
{
	//Person p;
	//Student s;

	Person* p = new Person;
	p->BuyTicket();
	delete p;

	p = new Student;
	p->BuyTicket();
	delete p; // p->destructor() + operator delete(p)
} 