#include <iostream>
#include <queue>
using namespace std;
void test() 
{
	//默认为大堆
	//priority_queue<int>pq;
	//小堆(仿函数实现小堆)——后面实现仿函数
	//priority_queue<int,deque<int>,greater<int>>pq;deque与vector的去别在于deque可以前后插入删除
	priority_queue<int,vector<int>,greater<int>>pq;
	pq.push(1);
	pq.push(2);
	pq.push(6);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}

}
int main()
{
	test();
	return 0;
}