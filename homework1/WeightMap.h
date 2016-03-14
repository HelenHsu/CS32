#ifndef WEIGHTMAP_INCLUDED
#define WEIGHTMAP_INCLUDED

#include "Map.h"
#include <string>
using namespace std;

class WeightMap
{
 public:
	WeightMap();
	bool enroll(std::string name, double startWeight);
	double weight(std::string name) const;
	bool adjustWeight(std::string name, double amt);
	int size() const;
	void print() const;
 private:
	Map m_Map; 
};


#endif//WEIGHTMAP_INCLUDED
