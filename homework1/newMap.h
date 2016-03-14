//newMap.h

#ifndef NEWMAP_INCLUDED
#define NEWMAP_INCLUDED

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
	Map(int n);
	Map(const Map& other);
	~Map();
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
	memberType* member;
	int count;
	int maxItems;
};

#endif //NEWMAP_INCLUDED
