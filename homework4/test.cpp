#include "Map.h"
#include<iostream>
#include<cassert>
using namespace std;

class Coord
{
 public:
	Coord(int r, int c):m_r(r),m_c(c){}
	Coord():m_r(0),m_c(0){}
	double r() const{return m_r;}
	double c() const{return m_c;}
 private:
	double m_r;
	double m_c;
};

int main()
{
	Map<int,double> test;
	test.insert(12,2233.9);
	test.insertOrUpdate(33,55.887);
	test.update(12,1.2);
	assert(test.contains(12)==true);
	int index=0;
	int key;
	double value;	
	test.get(index,key,value);
	assert(key==12);
	assert(value==1.2);
	//this is wrong!
//	Map<Coord,int> mpi;
//	mpi.insert(Coord(40,10),32);
	
	cout<<"pass all test"<<endl;
}
