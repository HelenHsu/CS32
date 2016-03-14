//testnewMap.cpp

#include "newMap.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()

{
	Map a(1000);
	Map b(5);
	Map c;
//	Map d(-1);
	KeyType k[6] = {"A","BB","CCC","D","EE","FFF"};
	ValueType v = 11;
	for (int n=0;n<5;n++)
		assert(b.insert(k[n],v));
	assert(!b.insert(k[5],v));
	a.swap(b);
	assert(!a.insert(k[5],v)&& b.insert(k[5],v));
	cerr<<"Pass the test!"<<endl;
}
