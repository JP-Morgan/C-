#include <iostream>
#include <queue>
using namespace std;
void test() 
{
	//Ĭ��Ϊ���
	//priority_queue<int>pq;
	//С��(�º���ʵ��С��)��������ʵ�ַº���
	//priority_queue<int,deque<int>,greater<int>>pq;deque��vector��ȥ������deque����ǰ�����ɾ��
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