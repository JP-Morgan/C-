#include "Date.h"
void Test()
{
	Date a1(2023, 4, 26);
	Date a2(2023, 4, 27);

	a1+=100;
	a1.Print();
	Date a4=a2 + 100;
	Date a3(a2.operator+(100));
	a2.Print();
	a3.Print();
} 
void Test2()
{
	Date a1(2023, 5, 5);
	Date a2(2023, 5, 5);
	Date a3(2023, 5, 5);
	a1 -= 50;
	
	a1.Print();
	
	a2 -= 100;
	a2.Print();
	
	Date a4 = a3 - 100;
	a4.Print();
}
void Test3()
{
	Date a1(2023, 5, 5);
	a1 += 100;
	a1.Print();
}
int main()
{
	Test2();
	return 0;
}