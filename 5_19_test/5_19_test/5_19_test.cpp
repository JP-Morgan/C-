#include <iostream>
using namespace std;
//C内存管理
//void test()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//	int* p2 = (int*)calloc(4, sizeof(int));
//	int* p3 = (int*)realloc(p2, sizeof(int) * 10);
//	free(p3);
//}

// 针对内置类型 new/delete与malloc/free没有本质的区别，只有用法的区别
// new/delete用法简化

void test()
{
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	int* n1 = new int;
	delete n1;
	//申请5个int的数组
	int* n2 = new int[5];
	//申请1个int对象，初始化为(5)
	int* n3 = new int(5);
	//c++11new[]用{}初始化。
	int* n4 = new int [5] {1, 2, 3};
	delete[] n2;
	delete n3;
	delete[] n4;

}
class A
{
public:
	//如果不提供默认构造
	//就要A* p2 = new(10);初始化
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
	//  在堆上申请空间
	A* p1 = (A*)malloc(sizeof(A));
	if (p1 == nullptr)
	{
		perror("malloc fail");
		return 0;
	}
	//释放空间
	free(p1);
	//在堆上申请空间，用构造函数初始化
	A* p2 = new A;
	//调用析构函数清理对象中的资源，在做释放空间
	delete p2;
	cout << endl << endl;
	//总结：new/delete 是为自定义类型准备的，不仅在堆申请出来，还会调用构造和析构和初始化和清理；
	A* n1 = new A[10];//内容待定    //如果没有默认构造函数那就要——A* n1 = new A[10]{1,2,3,4,5};
					              //但花括号元素个数必须等于[个数]否则就会报错
	delete []n1;
	// 针对内置类型 new/delete一定要匹配使用否则要出大问题

	return 0;
}