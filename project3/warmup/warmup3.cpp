#include <list>
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

//remove the movies in li with a rating below 50 and destroy them
//it is acceptable if the order of the remaining movies is not the same as in the original list.

void removeBad(list<Movie*>& li)
{
	list<Movie*>::iterator it;
	for(it=li.begin();it!=li.end();)
	{
		if ((*it)->rating()<50)
		{ 	list<Movie*>::iterator temp = it;
			delete *temp;
			it=li.erase(temp);
		}	
		else
			it++;
	}
}
void test()
{
	int a[8]={85,80,30,70,20,15,90,10};
	list<Movie*> x;
	for (int k=0; k<8; k++)
		x.push_back(new Movie(a[k]));
	assert(x.size()==8 && x.front()->rating()==85 && x.back()->rating()==10);
	removeBad(x);
	cerr<<"the size of the list now is "<<x.size()<<endl;
	cerr<<"the size of the destroyedOnes now is "<<destroyedOnes.size()<<endl;
	assert(x.size()==4&& destroyedOnes.size()==4);
	vector<int> v;					
	for (list<Movie*>::iterator p =x.begin(); p!= x.end(); p++)		
	//build vector by using the list
	{
		Movie* mp = *p;
		//delete *p;
		v.push_back(mp->rating());	
	}
	//Aside: in c++ 11, the above loop could be...
	sort(v.begin(),v.end());
	int expect[4]={70,80,85,90};
	for (int k=0; k<4; k++)
		assert(v[k]==expect[k]);
	int expectGone[4]={10,15,20,30};
	sort(destroyedOnes.begin(),destroyedOnes.end());
	for (int k=0; k<4; k++)
	{	assert(destroyedOnes[k]==expectGone[k]);
	}
	list<Movie*>::iterator it;
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
