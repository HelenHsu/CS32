#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	q.push(6);
	q.push(11);
	int n = q.size();
	while (!q.empty())
	{	
		
		cout<<"The number "<<n-q.size()+1<<" of the queue is "<<q.front()<<endl;
		q.pop();
	}

}

