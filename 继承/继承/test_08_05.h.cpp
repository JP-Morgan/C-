#include "test.h"
//int main()
//{
//	Student a;
//	Person b;
//	b = a;
//	//a = b；父不可以给子，因为父有的子没有
//	a.print_aeg();
//	a.print_naem();
//	int h = 1;
//
//	Person& g = a;//进行了切割/切片
//	/*double& q = h;*/
//}
//int main()
//{
//	Student a;
//	Person b;
//	a.num();
//	a.Person::num();//可以强制调用父类的同名成员
//	return 0;
//}
//int main()
//{
//	teacher t;
//	return 0;
//}
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;
	return 0;
}