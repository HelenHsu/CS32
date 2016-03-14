/////////////////////////////////////////////////////////////////////////////////
// linear.cpp
// CS32 Homework3
// Problem 2
/////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;
bool somePredicate(double x)
{
	return x<0;
}

  // Return true if the somePredicate function returns true for at
  // least one of the array elements, false otherwise.
bool anyTrue(const double a[], int n)
{
	if (n==0)
	{	cerr<<"anyTrue returns False!"<<endl;	//not found any for all
		return false;
	}
	if (somePredicate(a[0]))			
	{	cerr<<"anyTrue returns True!"<<endl;	//once found
		return true;
	}
    return anyTrue(a+1,n-1);  
}

  // Return the number of elements in the array for which the
  // somePredicate function returns true.
int countTrue(const double a[], int n)
{
	if (n==0)
		return 0;
    	return (somePredicate(a[0])?1:0)+countTrue(a+1,n-1);  //if true count else dont
}

  // Return the subscript of the first element in the array for which
  // the somePredicate function returns true.  If there is no such
  // element, return -1.
int firstTrue(const double a[], int n)
{
	if(n==0)
		return -1;
	if(somePredicate(a[0]))
		return 0;
    return (firstTrue(a+1,n-1)==-1?-1:1+firstTrue(a+1,n-1)); //return the index or -1
}

  // Return the subscript of the smallest element in the array (i.e.,
  // the one whose value is <= the value of all elements).  If more
  // than one element has the same smallest value, return the smallest
  // subscript of such an element.  If the array has no elements to
  // examine, return -1.
int indexOfMin(const double a[], int n)
{	//int index=0,min=10000;
	if (n==0)
		return -1;
	else
	if (indexOfMin(a,n-1)==-1)
		return 0;
	else
		return(a[n-1]<a[indexOfMin(a,n-1)]? (n-1):indexOfMin(a,n-1));  // This is incorrect.
}

  // If all n2 elements of a2 appear in the n1 element array a1, in
  // the same order (though not necessarily consecutively), then
  // return true; otherwise (i.e., if the array a1 does not include
  // a2 as a not-necessarily-contiguous subsequence), return false.
  // (Of course, if a2 is empty (i.e., n2 is 0), return true.)
  // For example, if a1 is the 7 element array
  //    10 50 40 20 50 40 30
  // then the function should return true if a2 is
  //    50 20 30
  // or
  //    50 40 40
  // and it should return false if a2 is
  //    50 30 20
  // or
  //    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2)
{
	if (n2==0)
		return true;
	if (n1==0)
		return false;
	if(a1[0]==a2[0])
		return(includes(a1+1,n1-1,a2+1,n2-1));
	else
		return(includes(a1+1,n1-1,a2,n2));
}
int main()
{
	double a[6]={3,2,1,0,-1,-2};
	double b[6]={3,4,5,6,7,8};
	assert(anyTrue(a,5)==true);
	assert(countTrue(a,6)==2);
	assert(firstTrue(a,6)==4);
	assert(firstTrue(b,6)==-1);
	assert(indexOfMin(a,6)==5);
	assert(indexOfMin(b,6)==0);
	assert(indexOfMin(b,0)==-1);
	double a1[7]={10,50,40,20,50,40,30};
	double a2[3]={50,20,30};
	double a3[3]={50,40,40};
	double a4[3]={50,30,20};
	double a5[3]={10,20,20};
	assert(includes(a1,7,a2,3)==true);
	assert(includes(a1,7,a3,3)==true);
	assert(includes(a1,7,a4,3)==false);
	assert(includes(a1,7,a5,3)==false);
	cerr<<"Passed all test!"<<endl;
}
