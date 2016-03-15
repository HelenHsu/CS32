//warmup2.cpp
//practice and prepare for proj3
////////////////////////////////////////////////////////////
#include<vector>
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;

//remove the odd integer from vi
//it is acceptable if the order of the remaining even integer is not the same as in the original list
void removeOdds(vector<int>& vi)
{	vector<int>::iterator it;
	for(it=vi.begin();it!=vi.end();)
	{
		if(*it%2==1)
		{				//dont have to define it again 
			it=vi.erase(it);	//it points to the next item after erase
		}
		else
			it++;			//if not erase, it++
	}
}

void test()
{
	int a[8]= {2,8,5,6,7,3,4,1};
	vector<int> x(a,a+8);	//construct x from the array
	assert(x.size()==8&& x.front()==2 &&x.back()==1);
	removeOdds(x);
	assert(x.size()==4);
	vector<int> v(x.begin(),x.end());
	sort(v.begin(),v.end());
	int expect[4] = {2,4,6,8};
	for (int k=0; k<4;k++)
		assert(v[k] == expect[k]);
}

int main()
{
	test();
	cout<<"Passed"<<endl;
}
