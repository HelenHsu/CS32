#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
	stack<int> si;
	si.push(10);
	si.push(20);
	if(!si.empty())
		cout<<si.top()<<" ";	//output 20
	si.pop();		
	cout<<si.size()<<" ";		//output 1
	cout<<si.top()<<" ";		//output 10
	cout<<endl;

	queue<int> qi;
	qi.push(10);
	qi.push(20);
	if (! qi.empty())
		cout<<qi.front()<<" ";	//output 10
	cout<<qi.back()<<" ";		//output 20
	qi.pop();
	cout<<qi.size()<<" ";		//output 1
	cout<<qi.front()<<" ";		//output 20
	cout<<endl;

	vector<int> vi;
	vi.push_back(10);
	vi.push_back(20);
	vi.push_back(30);
	cout<<vi.size()<<" ";
	cout<<vi.front()<<" ";
	cout<<vi.back()<<" ";
	vi[1]=40;
	//vi[3]=50; 				//would be undefined behavior, since its out of range
	for (size_t k=0; k<vi.size();k++)	//vi.size() returns a specific type called size_t
		cout<<vi[k]<<" ";		//output 10 40 30
	cout<<endl;
	vi.pop_back();
	for (size_t k=0; k<vi.size();k++)	
		cout<<vi[k]<<" ";		//output 10 40 
	vi.at(1)=60;				//the same as vi[k]
	//vi.at(3)=70;				//but throws an exception if out of range
						//vi.at() is safe; vi[k] is fast
	vector<double> vd(10);			//create 10 double with value 0.0
	vector<string> vs(10,"Hello");		//create 10 string "Hello"
	int a[5] = {10,20,30,40,50};
	vector<int> vx(a,a+5);			//vx.size()is 5, vx[0] is 10 
	cout<<endl;

	list<int> li;
	li.push_back(20);
	li.push_back(30);
	li.push_front(10);
	cout<<li.size()<<" ";		//output 3
	cout<<li.front()<<" ";		//output 10
	cout<<li.back()<<" ";		//output 30
	li.push_front(40);
	li.pop_front();			//pop off 40
	for(list<int>::iterator p = li.begin();p!=li.end();p++)
		cout<<*p<<" ";		//write out 10 20 30
	cout<<endl;
	list<double> ld(10);		//ld.size() is 10, each 0.0
	list<string> ls(10,"Hello");	//ls.size() is 10, each "Hello"
	vector<string> vs1(ls.begin(), ls.end());	//vs1.size()is 10, each "Hello" 
	list<int>::iterator p = li.end();		//li: 10 20 30 p
	p--;						//li: 10 20 30(p) 
	p--;						//li: 10 20(p) 30
	//p-=2;won't compile
	list<int>::iterator q = li.insert(p,40);	//li: 10 40(q) 20(p) 30
	list<int>::iterator r = li.erase(p);		//li: 10 40(q) 30(r)
							//now is undefinied to use p
	vi.at(0)=10;
	vi.at(1)=20;
	vi.push_back(30);				//vi: 10 20 30 
	vector<int>::iterator p1 = vi.end()-2;		//vi: 10 20(p1) 30 
	vector<int>::iterator q1 = vi.insert(p1,40);	//vi: 10 40(q1) 20 30
							//since the rest of the array all moved, now is undefined to use p1
	vector<int>::iterator p2 = vi.erase(q1);		//vi: 10 20(p2) 30

}
