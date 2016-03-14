#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	s.push(6);
	s.push(11);
	while (!s.empty())
	{	
		cout<<"The number "<<s.size()<<" of the stack is "<<s.top()<<endl;
		s.pop();
	}

}
//class Poin
