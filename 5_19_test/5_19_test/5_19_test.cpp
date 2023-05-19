#include <iostream>
using namespace std;
//C�ڴ����
//void test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	free(p3);
//}

// ����������� new/delete��malloc/freeû�б��ʵ�����ֻ���÷�������
// new/delete�÷���

void test()
{
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	int* n1 = new int;
	delete n1;
	//����5��int������
	int* n2 = new int[5];
	//����1��int���󣬳�ʼ��Ϊ(5)
	int* n3 = new int(5);
	//c++11new[]��{}��ʼ����
	int* n4 = new int [5] {1, 2, 3};
	delete[] n2;
	delete n3;
	delete[] n4;

}
class A
{
public:
	//������ṩĬ�Ϲ���
	//��ҪA* p2 = new(10);��ʼ��
	/*A(int a)
		:_a(a)
	{
	}*/
	A(int a = 0)
		:_a(a)
	{
		i++;
		cout << "_a(a):"<< i << endl;
	}
	~A()
	{
		j++;
		cout << "~A():"<< j << endl;
	}
private:
	int _a;
	static int i;
	static int j;
};
int A::i = 0;
int A::j = 0;

int main()
{
	//  �ڶ�������ռ�
	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == nullptr)
	{
		perror("malloc fail");
		return 0;
	}
	//�ͷſռ�
	free(p1);
	//�ڶ�������ռ䣬�ù��캯����ʼ��
	A* p2 = new A;
	//��������������������е���Դ�������ͷſռ�
	delete p2;
	cout << endl << endl;
	//�ܽ᣺new/delete ��Ϊ�Զ�������׼���ģ������ڶ����������������ù���������ͳ�ʼ��������
	A* n1 = new A[10];//���ݴ���    //���û��Ĭ�Ϲ��캯���Ǿ�Ҫ����A* n1 = new A[10]{1,2,3,4,5};
					              //��������Ԫ�ظ����������[����]����ͻᱨ��
	delete []n1;
	// ����������� new/deleteһ��Ҫƥ��ʹ�÷���Ҫ��������

	return 0;
}