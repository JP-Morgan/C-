#include <iostream>
using namespace std;

//int main()
//{
//    //c���淨
//    int* b = (int*)malloc(sizeof(int));
//    free(b);
//
//    //���
//    int* b = (int*)malloc(sizeof(int) * 10);
//    free(b);
//
//    //c++���淨
//    int* a = new int;
//    delete a;
//
//    //���
//    int* a = new int[10];//�����ǿ�(����)10��int������
//    delete[] a;
//
//    int* a = new int(10);//��(����)һ��intΪ��ʼ��Ϊ10
//    delete a;
//
//    //����ĳ�ʼ��
//    int* a = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//�����ǿ�(����)10��int������
//    delete[] a;
//    return 0;
//}

//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//	//explicit Date(int year)
//	//	:_year(year)
//	//{
//	//	cout << "Date(int year)" << endl;
//	//}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//
//	}
//private:
//	int _year;
//};
////�ܽᡪ���������ֹ���������캯������ʽת���������ùؼ���explicit�����ι��캯����
//int main()
//{
//	Date d1(2023);
//	Date d2 = 2023;
//	const Date& d3 = 2023;
//	return 0;
//}

//��������
//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{
//
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date a1(2023);//������������������ֻ��һ�У�������������������һ�������Ͽ����ӳ���������
//	Date(2023);//
//	return 0;
//}


//static��̬��Ա
//class A
//{
//public:
//	A()
//	{
//		++_sum;
//	}
//	A(const A& sum)
//	{
//		++_sum;
//	}
//	//��̬��Ա����û��thisָ�롣�����Է��ʷǾ�̬��Ա
//	static int GitCont()
//	{
//		return _sum;
//	}
//
//private:
//	//����
//	//��̬��Ա���������������࣬���������������������ڼ䣬���ھ�̬��
//	static int _sum;
//};
//
//int A::_sum = 0;
//
//int main()
//{	
//
//	return 0;
//}


//ֻ������ջ������
class MyClass
{
public:
	//�������ֵ�û�а취ʹ����զ���أ�
	/*MyClass CreateObj()
	{
		MyClass so;
		return so;
	}*/

	//ʹ�þ�̬����
	static MyClass CreateObj()
	{
		MyClass so;
		return so;
	}
private:
	MyClass(int x = 0, int y = 0)
		:_i(x)
		,_j(y)
	{

	}
private:
	int _i;
	int _j;
};

int main()
{
	MyClass A1 = MyClass::CreateObj();
	return 0;
}