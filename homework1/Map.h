//Map.h
//problem1. decide which member function to const
//problem2. modify the class definition with typedef

#ifndef MAP_INCLUDED
#define MAP_INCLUDED

#include <string>
using namespace std;

const int DEFAULT_MAX_ITEMS = 200;
typedef std::string KeyType;
typedef double ValueType;

//typedef int KeyType;
//typedef std::string ValueType;

struct memberType
{
 KeyType m_key;
 ValueType m_value;
};

class Map
{
 public:
	Map();
//	~Map();
	Map &operator=(const Map& other);
	bool empty() const;
	int size() const;
	bool insert(const KeyType& key, const ValueType& value);
	bool update(const KeyType& key, const ValueType& value);
	bool insertOrUpdate(const KeyType& key, const ValueType& value);
	bool erase(const KeyType& key);
	bool contains(const KeyType& key) const;
	bool get(const KeyType& key, ValueType& value) const;
	bool get(int i, KeyType& key, ValueType& value) const;
	void swap(Map& other);
 private:
//	KeyType m_key[DEFAULT_MAX_ITEMS];
//	ValueType m_value[DEFAULT_MAX_ITEMS];
	memberType member[DEFAULT_MAX_ITEMS];
	int count;
};

#endif //MAP_INCLUDED
