#include <iostream>
using namespace std;


//�麯������дϸ��
// 1.���������д�麯�����Բ���virtual --�����鶼�ӣ�
//	 Ҫ����ͬ������������ֵ�������б���ͬ��
// 2.Э�䷵��ֵ���Բ�ͬ������Ҫ�󷵻�ֵ�����Ǹ��ӹ�ϵָ�������
//
//class Person {
//public:
//	virtual void BuyTicket() const{ cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() const{ cout << "��Ʊ-���" << endl; }
	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��
	Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶��������
	����ʹ��*/
	/*void BuyTicket() { cout << "��Ʊ-���" << endl; }*/
//};
// ��̬������
// 1.���ú�����д�麯��
// 2.����ָ���������
// 
// ��̬����ͬ�Ķ�����ù�ȥ�����ò�ͬ����
// ��̬���ÿ�ָ��Ķ���
// ��ͨ���󣬿����ǵ�ǰ��������
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
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }

	~Student() {
		cout << "~Student()" << endl;
		delete[] ptr;
	}

protected:
	int* ptr = new int[10];
};

// ���������������麯����Ϊʲô��Ҫ���麯����
// ����������virtual���ǲ����麯����д��
// �ǣ���Ϊ�������������������destructor���ͳһ������
// ΪʲôҪ��ô�����أ���ΪҪ�����ǹ�����д
// ��ΪʲôҪ�����ǹ�����д�أ�
// ��Ϊ����ĳ���

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