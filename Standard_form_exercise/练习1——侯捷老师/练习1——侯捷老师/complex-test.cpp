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
		return a._x + a._y;//Ϊʲô������a._x�أ���Ϊͬclass�Ķ����໥Ϊ��Ԫ����
	}
	void PRINTF()
	{
		cout << _x << " " << _y << endl;
	}

	inline test&
		__doapl(test* ths, const test& a)
	{
		return *ths;//������
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