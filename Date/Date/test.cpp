#include "Date.h"
void Test()
{
	Date a1(2023, 4, 26);
	Date a2(2023, 4, 27);
	a1+=100;
	a1.Print();
	a2 + 100;
	Date a3(a2.operator+(100));
	a2.Print();
	a3.Print();
} 
int main()
{
	Test();
	return 0;
}