#include <iostream>
using namespace std;


//虚函数的重写细节
// 1.派生类的重写虚函数可以不加virtual --（建议都加）
// 2.要求三同函数名，返回值，参数列表相同、
// 3.协变返回值可以不同，但是要求返回值必须是父子关系指针和引用
//
class Person {
public:
	virtual void BuyTicket() const{ cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() const{ cout << "买票-半价" << endl; }
	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
	这样使用*/
	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
};
// 多态的条件
// 1.调用函数重写虚函数
// 2.基类指针或者引用
// 
// 多态，不同的对象调用过去，调用不同函数
// 多态调用看指向的对象
// 普通对象，看的是当前调用类型
//
void Func(const Person& p)
{
	p.BuyTicket();
}
int main()
{
	Func(Person());
	Func(Student());
	return 0;
}