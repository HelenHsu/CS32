#include "WeightMap.h"
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
	WeightMap list;
	list.enroll("Helen",120);
	list.enroll("Jeremy",150.03);
	list.enroll("Ben",180);
	assert(list.weight("Jeremy")==150.03);
	assert(list.weight("Helen")==120);

	assert(list.weight("Anna")==-1);

	assert(list.adjustWeight("Ben", -30)==true);
	assert(list.weight("Ben")==150);
	assert(list.size()==3);

	cerr<<"Pass above test. Here is the list:"<<endl;
	list.print();
}
