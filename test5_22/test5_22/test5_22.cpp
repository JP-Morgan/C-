#include <iostream>
#include <string>
using namespace std;
//����ģ��
//T����ת��Ϊ�������Ͱ����Զ�������
//template <typename T>
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 0, b = 10;
//	double c = 1.1, d = 9.9;
//	Swap(a, b);
//	Swap(c, d);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	return 0;
//} 

// ���ͱ��
// ��ģ��
// template <class T>
//template <typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//template <typename T1,typename T2>
//T1 Fang(T1& a, T2& b)
//{
//	cout << a << " " << b << endl;
//	return a;
//}
//���ǵ��õĲ���ģ�����ģ��ʵ�������ɵľ��庯��
//ģ����ݵ��ã��Լ��Ƶ�ģ����������ͣ�ʵ������Ӧ�ĺ�����
//int main()
//{
//	int x = 10, y = 20;
//	int z = Fang(x, y);
//	cout << z << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}

//����ģ���ʵ������Ϊ����1.��ʽ���ͣ���ʾ����
//template <typename T1,typename T2>
//T1 Fang(const T1& a,const T2& b)
//{
//	cout << a << " " << b << endl;
//	return a+b;
//}


//template <typename T1>
//T1 Fang(const T1& a, const T1& b)
//{
//	cout << a << " " << b << endl;
//	return a + b;
//}
//template <typename T>
//T* Alloc(int n)
//{
//	return new T[n];
//}
//int main()
//{
//	int a = 10;
//	double b = 9.99;
//	//ʵ�δ��ݵ����ͣ�����T������
//	int x = Fang(a, (int)b);
//	//��ʾʵ����
//	int x = Fang<int>(a, b);
//	cout << x << endl;
//	//��Щ����û�а취�Զ��ƣ�ֻ����ʾʵ����
//	double* p1 = Alloc<double>(10);
//	//�����������
//	// ��ͨ�࣬������������һ����
//	// ��ģ�壬���������Ͳ�һ����
//	// �磺
//	// ������stack
//	// ���ͣ�stack<T>
//	//��ģ��
//	return 0;
//}


//STL
//string
int main()
{

	return 0;
}