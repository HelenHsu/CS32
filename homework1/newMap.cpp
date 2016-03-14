
//////////////////////////////////////////////////////////////////
/*
newMap.cpp
//use pointer instead of array

struct StructureType{
 KeyType m_key;
 ValueType m_value;}

private member
StructureType member[DEFAULT_MAX_ITEMS]
int count;
int maxItems;
*/
/////////////////////////////////////////////////////////////////


#include "newMap.h"
#include <string>
#include <iostream>
using namespace std;

Map::Map():member(new memberType[DEFAULT_MAX_ITEMS]),count(0),maxItems(DEFAULT_MAX_ITEMS){};
Map::Map(int n):member(new memberType[n]),count(0),maxItems(n)
{
/*
	if (n<0)
	{	
		cout<<"Ilegal input"<<endl;
		exit(1);
	}
*/
};
Map::~Map()
{
	delete [] member;
};

Map::Map(const Map& other)
{
	maxItems = other.maxItems;
	count = other.count;
	member = new memberType[count];	////////////////
	for (int i=0; i< count;i++)
	{
		member[i].m_key = other.member[i].m_key;
		member[i].m_value = other.member[i].m_value;
	}
};

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
	if (!(count < maxItems))
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
	if (count < maxItems)
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
			member[count-1]= member[count];
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
	if( &other == this)
	 	return (*this);
	delete [] this->member;	////////////////////////////////////////	
	maxItems = other.maxItems;
	count = other.count;
	member = new memberType[maxItems];	////////////////
	for (int i=0; i< count;i++)
	{
		this->member[i].m_key = other.member[i].m_key;
		this->member[i].m_value = other.member[i].m_value;
	}
	return (*this);	
};

void Map::swap(Map& other)
{
/*	
	Map* temp = new Map();
	*temp =* this;
	*this = other;
	other =* temp;
	delete temp; 
*/
	Map temp= *this;
	*this= other;
	other = temp;
};

