#include "BinaryFile.h"
#include <cstring>
int main()
{

	BinaryFile bf;
//the task is to create a data structure to implement functions below;	

	DiskList x("myfile.dat");
	DiskNode Fred("Fred");
	DiskNode Lucy("Lucy");
	DiskNode Nancy("Nancy");
	DiskNode Lucy2("Lucy");
	DiskNode Fan("Fan");	
	x.push_front(Fred);
	x.push_front(Lucy);
	x.push_front(Nancy);
	x.push_front(Lucy2);
	x.push_front(Fan);
	x.printAll();
//	x.printLastNode();
//	x.printSecondLastNode();
	x.remove("Lucy");
	x.printAll();

}


