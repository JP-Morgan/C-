/*
* ��ʼ���б�
* ÿһ����Ա�����ڳ�ʼ���б���ֻ���Գ�ʼ��һ��
* ���ó�Ա����
* const��Ա����
* �Զ������ͳ�Ա(����û��Ĭ�Ϲ���ĺ���)
*/
#include <iostream>
using namespace std;
class AAA
{
public:
	AAA(int a)
		:_A(a)
	{}
private:
	int _A;
};

class MyClass
{
public:
	//��ʼ���б�����ĳ�Ա�����λ��
	MyClass(int a, int ref)
		:_asd(a)
		, _ref(ref)
		, _n(10)
	{}
private:
	//�������ĵط�
	AAA _asd;//Ĭ�Ϲ��죨ֻҪ����ֵ�Ķ���Ĭ�Ϲ��죩

	//����:�������ڶ���ʱ��ʼ��(������const)
	int& _ref;//����
	const int _n;//const
	int x = 10;//�����ʾ����ȱʡ
};
int main()
{
	//�������嶨��ĵط�
	MyClass a(10, 20);
	return 0;
}