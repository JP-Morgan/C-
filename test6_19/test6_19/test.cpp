#include <iostream>
using namespace std;
int main()
{
	const char* str = new char[100];
	str = "asdfghjkl\0";
	int a = 6;
	cout << (str)+a << endl;
}