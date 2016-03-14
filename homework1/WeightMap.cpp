//WeightMap.cpp
///////////////////////below are class Map//////////////////////////
/*
typedef std::string KeyType;
typedef double ValueType;

struct memberType
{
 KeyType m_key;
 ValueType m_value;
};

class Map
{
 public:
	Map();
	Map &operator=(const Map& other);
	bool empty() const;
	int size() const;
	bool insert(const KeyType& key, const ValueType& value);
	bool update(const KeyType& key, const ValueType& value);
	bool insertOrUpdate(const KeyType& key, const ValueType& value);
	bool erase(const KeyType& key);
	bool contains(const KeyType& key) const;
 	bool get(const KeyType& key, ValueType& value);
	bool get(int i, KeyType& key, ValueType& value);
	void swap(Map& other);
 private:
	memberType member[DEFAULT_MAX_ITEMS];
	int count;
};
*/

////////////////////////////////////////////////////////////////////////
//class WeightMap
///////////////////////////////////////////////////////////////////////

#include "WeightMap.h"
#include "Map.h"
#include <iostream>
using namespace std;

WeightMap::WeightMap():m_Map(){};
bool WeightMap::enroll(std::string name, double startWeight)
{
	if (startWeight > 0)
		if ( m_Map.insert(name, startWeight))
			return true;
	return false;
}
double WeightMap::weight(std::string name) const
{	double result;
	if (m_Map.get(name,result))
		return result;
	else
		return -1;
}
bool WeightMap::adjustWeight(std::string name, double amt)
{
	double result= weight(name)+amt;
	if (result < 0) 
		return false;
	else 
	{
		return m_Map.update(name, result);  //will return false when no such key exists
	}
}
int WeightMap::size() const
{
	return m_Map.size();
}
void WeightMap::print() const
{
	std::string name;
	double weight;
	for(int i=0; i < m_Map.size(); i++)
	{	
		if(m_Map.get(i,name,weight))
			cout<< name<< " " <<weight<<endl;
	
	}
}



