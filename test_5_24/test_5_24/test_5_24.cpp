#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a1("dididididididididi");
	cout << a1 << endl;
	for (size_t i = 0; i < a1.size(); i++)
	{
		a1[i]++;
	}
	cout << endl;
	//µü´úÆ÷(ÏñÖ¸Õë)
	string::iterator it = a1.begin();
	while (it != a1.end())
	{
		(*it)++;
		it++;
	}
	it = a1.begin();
	while (it != a1.end())
	{
		cout << *it << " ";
		++it;
	}
	for (auto ch : a1)
	{
		cout << ch << endl;
	}
	return 0;
}
