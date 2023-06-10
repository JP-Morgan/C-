#include <iostream>
using namespace std;
class test
{
public:
	test(int x = 0, int y = 0)
		:_x(x), _y(y)
	{
	}
	test fun(const test& a)
	{
		return a._x + a._y;//为什么可以用a._x呢？因为同class的对象相互为友元！！
	}
	void PRINTF()
	{
		cout << _x << " " << _y << endl;
	}

	inline test&
		__doapl(test* ths, const test& a)
	{
		return *ths;//解引用
	}
private:
	int _x;
	int _y;
};
int main()
{
	test a(10, 20);
	test b;
	test c = b.fun(a);
	c.PRINTF();
	return 0;
}