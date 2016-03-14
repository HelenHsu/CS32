//////////////////////////////////////////////////////////////////
/*
Map.cpp
problem1. decide which member function to const
problem2. modify the class definition with typedef
problem3. implement the member functions, change types and test

struct StructureType{
 KeyType m_key;
 ValueType m_value;}

private member
StructureType member[DEFAULT_MAX_ITEMS];
int count;
*/
/////////////////////////////////////////////////////////////////


#include "Map.h"
#include <string>
#include <iostream>
using namespace std;

Map::Map():count(0){};
/*
Map& Map::operator=(const Map& other)
{
	Map temp(other);
	swap(temp);
	return *this;
};
*/
bool Map::empty() const
{
	if (count==0) 
		return true;
	else 
		return false;
};
int Map::size() const
{
	return count;
};
bool Map::insert(const KeyType& key, const ValueType& value)
{	
	if (!(count < DEFAULT_MAX_ITEMS))
		return false;
	int i;
	for(i=0; i < count; i++)
	{	if (member[i].m_key == key)
			return false;
	}
	member[i].m_key = key;
	member[i].m_value = value;
	count ++;
	return true;
};
bool Map::update(const KeyType& key, const ValueType& value)
{
	int i;
	for (i=0; i < count;i++)
	{
		if ( member[i].m_key == key)
		{	
			member[i].m_value = value;
			return true;
		}	
	}
	return false;
};
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
	int i;
	for (i=0; i < count;i++)
	{
		if (member[i].m_key == key)		//may i use contains?
		{	
			member[i].m_value = value;
			return true;
		}	
	}					///////can i use insert?
	if (count < DEFAULT_MAX_ITEMS)
	{	member[i].m_key = key;
		member[i].m_value = value;
		return true;
	}					/////can i use update?
	return false;

};
bool Map::erase(const KeyType& key)
{
	int i;
	for (i=0; i < count;i++)
	{
		if (member[i].m_key == key)
		{	
			member[i].m_key = member[count-1].m_key;
			member[i].m_value = member[count-1].m_value;
			//delete member[count-1];
			member[count-1]=member[count];
			count--;
			return true;
		}	
	}
	return false;
};
bool Map::contains(const KeyType& key) const
{
	int i;
	for (i=0; i < count; i++)
	{
		if (member[i].m_key == key)
		{	
			return true;
		}	
	}
	return false;
};
bool Map::get(const KeyType& key, ValueType& value) const
{
	int i;
	for (i=0; i < count;i++)
	{
		if (member[i].m_key == key)
		{	
			value = member[i].m_value;
			return true;
		}	
	}
	return false;
};
bool Map::get(int i, KeyType& key, ValueType& value) const
{
	if (i < count)
	{	key= member[i].m_key;
		value = member[i].m_value;
		return true;
	}
	return false;
};

Map& Map::operator=(const Map& other)
{
	if( &other ==this)
	 	return (*this);
//	delete [] member;
//	member[DEFAULT_MAX_ITEMS] = new memberType[DEFAULT_MAX_ITEMS];
	for (int i=0; i< DEFAULT_MAX_ITEMS;i++)
	{
		member[i].m_key = other.member[i].m_key;
		member[i].m_value = other.member[i].m_value;
	}
	count = other.size();
	return (*this);	
};

void Map::swap(Map& other)
{
///*
	Map* temp = new Map;
	*temp =* this;
	*this = other;
	other =* temp;
	delete temp; 
//*/
/*
	Map temp = new Map;
	temp.member = this -> member;
	temp.size() = this -> size();
	this -> member = other.member;
	this -> size() = other.size();
	other.member = temp.member;
	other.size() = temp.size();
	delete [] temp.member;
	delete temp.size();
*/
};

