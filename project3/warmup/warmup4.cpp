//warmup4.cpp
//preparing for CS32 project3
/////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;

vector<int> destroyedOnes;

class Movie
{
 public:
	Movie(int r):m_rating(r){}
	~Movie(){destroyedOnes.push_back(m_rating);}
	int rating() const{return m_rating;}
 private:
	int m_rating;
};

//remove the movies in v with a rating below 50 and destroy them
//it is acceptable if the order of the remaining movies is not the same as in the original list.

void removeBad(vector<Movie*>& v)
{
	vector<Movie*>::iterator it;
	for(it=v.begin();it!=v.end();)
	{
		if ((*it)->rating()<50)
		{ 	//vector<Movie*>::iterator temp = it;
			delete *it;
			it=v.erase(it);
		}	
		else
			it++;
	}
}
void test()
{
	int a[8]={85,80,30,70,20,15,90,10};
	vector<Movie*> x;
	for (int k=0; k<8; k++)
		x.push_back(new Movie(a[k]));
	assert(x.size()==8 && x.front()->rating()==85 && x.back()->rating()==10);
	removeBad(x);
	cerr<<"the size of the list now is "<<x.size()<<endl;
	cerr<<"the size of the destroyedOnes now is "<<destroyedOnes.size()<<endl;
	assert(x.size()==4&& destroyedOnes.size()==4);
	vector<int> v;					
	for (int k=0; k<4; k++)
		v.push_back(x[k]->rating());
	int expect[4]={70,80,85,90};
	sort(v.begin(),v.end());
	for (int k=0; k<4; k++)
		assert(v[k]==expect[k]);
	int expectGone[4]={10,15,20,30};
	sort(destroyedOnes.begin(),destroyedOnes.end());
	for (int k=0; k<4; k++)
	{	assert(destroyedOnes[k]==expectGone[k]);
	}

	vector<Movie*>::iterator it;
	for(it=x.begin();it!=x.end();)
	{
			delete *it;
			it=x.erase(it);
	}

} 

int main()
{
	test();
	cout <<"Passed"<<endl;
}
