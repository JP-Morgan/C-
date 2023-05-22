#include <iostream>
#include <string>
using namespace std;
//函数模板
//T可以转换为所有类型包括自定义类型
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

// 泛型编程
// 类模板
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
//我们调用的不是模板而是模板实例化生成的具体函数
//模板根据调用，自己推导模板参数的类型，实例化对应的函数；
//int main()
//{
//	int x = 10, y = 20;
//	int z = Fang(x, y);
//	cout << z << endl;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}

//函数模板的实例化分为两种1.隐式类型，显示类型
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
//	//实参传递的类型，推演T的类型
//	int x = Fang(a, (int)b);
//	//显示实例化
//	int x = Fang<int>(a, b);
//	cout << x << endl;
//	//有些函数没有办法自动推，只能显示实例化
//	double* p1 = Alloc<double>(10);
//	//声明定义分离
//	// 普通类，类名和类型是一样的
//	// 类模板，类名与类型不一样，
//	// 如：
//	// 类名：stack
//	// 类型：stack<T>
//	//类模板
//	return 0;
//}


//STL
//string
int main()
{

	return 0;
}