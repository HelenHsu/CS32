// Map.h

#ifndef MAP_INCLUDED
#define MAP_INCLUDED

#include <string>

typedef std::string KeyType;
typedef double ValueType;
//typedef int KeyType;
//typedef std::string ValueType;

//const int DEFAULT_MAX_ITEMS = 200;

class Map
{
  public:
    Map();
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
    struct Pair
    {
        KeyType   m_key;
        ValueType m_value;
    };
    struct Node
    {
	Pair value;
	Node* next;
	Node* prev;
    };
    Node *head;	//circular doubly-linked list
    int  m_size;                     // number of pairs in the map
    Node *find(const KeyType& key) const;	
      // if key exists, return pointer, else dummy node
    bool doInsertOrUpdate(const KeyType& key, const ValueType& value,
                          bool mayInsert, bool mayUpdate);
};
///////////////////////////////////////////////////////////////////////
// non member functions

bool combine(const Map& m1, const Map& m2, Map& result);
	//result might not be empty
	//key in one of m1, m2 --> a pair in result
	//key in both m1 and m2 && v1==v2 --> a pair in result
	//key in both m1 and m2 && v1!=v2 --> return false
	//else return true
void subtract(const Map& m1,const Map& m2, Map& result);
	//add those m1 keys, which are not in m2, into result
////////////////////////////////////////////////////////////////////////
// Inline implementations

inline
int Map::size() const
{
    return m_size;
}

inline
bool Map::empty() const
{
    return size() == 0;
}

inline
bool Map::contains(const KeyType& key) const
{
	Node * p =  find(key);
	if (p != head)
		return true;
	return false;
}

inline
bool Map::insert(const KeyType& key, const ValueType& value)
{
    return doInsertOrUpdate(key, value, true /* insert */, false /* no update */);
}

inline
bool Map::update(const KeyType& key, const ValueType& value)
{
    return doInsertOrUpdate(key, value, false /* no insert */, true /* update */);
}

inline
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    return doInsertOrUpdate(key, value, true /* insert */, true /* update */);
}

#endif // MAP_INCLUDED
