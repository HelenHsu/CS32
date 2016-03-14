// Map.cpp

///////////////////////////////////////
/*
class Map{ 
 private:
    struct Pair{	KeyType   m_key;
        		ValueType m_value;	};
    struct Node{	Pair value;
			Node* next;		
			Node* prev;		};}
    Node *head;
    int  m_size;
    int find(const KeyType& key) const;	
    bool doInsertOrUpdate(const KeyType& key, const ValueType& value,
                          bool mayInsert, bool mayUpdate);
};
*/
////////////////////////////////////////

#include "Map.h"
#include <iostream>
using namespace std;
Map::Map()
 : m_size(0)
{	
	head = new Node;	//points to dummy head
	head->next = head;
	head->prev = head;
//	ptr = head->next;	//set a ptr that is the next of head for outside using
}
Map::~Map()
{
	Node *p;
	p = head->next;
	while(p!= head)
	{
		Node *n = p->next;
		delete p;
		p = n;
	}
	delete p;
}
Map& Map::operator=(const Map& other)
{
	if (&other==this)
		return (*this);
	Node* temp = head->next;	
	while (temp !=head)		//delete current items
	{
		Node* ptr = temp->next;
		erase(temp->value.m_key);
		temp = ptr;
	}
	head = new Node;		//give a new dummy node
	head->next = head;
	head->prev = head;
	delete temp;
	m_size = 0;
	KeyType k;
	ValueType v;
	for (int i=0; i<other.size(); i++)	//put the copy items into this map
	{
		if(other.get(i,k,v))
			this->insert(k,v);
	}
	return *this;
}
bool Map::erase(const KeyType& key)
{
    Node* p = find(key);		
    if (p==head)			//if not found
        return false;
    p->prev->next = p->next;		//if found, link previous item to the next item
    p->next->prev = p->prev;
    m_size--;
    delete p;				//delete this item
    return true;
}

bool Map::get(const KeyType& key, ValueType& value) const
{
    Node *p = find(key);
    if (p== head)  			//if not found
        return false;
    value = p->value.m_value;		//if found, update value
    return true;
}

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if (i < 0  ||  i >= m_size)		//check if input is valid
        return false;
    Node *p =head->next;
    int n = 0;				//count from 0 to i-1
    while (p != head && n!= i )		//get the address of this item
    {
    	p = p->next;
	n++;
    }
    key = p->value.m_key;		//get the key and the value
    value = p->value.m_value;
    return true;
}

void Map::swap(Map& other)
{    //swap head
    Node* temp = head;
    head = other.head;
    other.head = temp;
/*     //or swap the whole Map?
    Map temp =* this;
    *this = other;
    other = temp;
*/
     //swap size
    int t = m_size;
    m_size = other.m_size;
    other.m_size = t;
}

Map::Node* Map::find(const KeyType& key) const
{
	//if found, return node pointer, else return dummy node pointer
	Node* p= head->next;
	while (p != head)
	{
		if (p->value.m_key == key)
			return p; 
		p = p->next;
	}
	return p;
}

bool Map::doInsertOrUpdate(const KeyType& key, const ValueType& value,
                           bool mayInsert, bool mayUpdate)
{
    Node* p = find(key);
    if (p != head) 	 			//found
    {
	if (mayUpdate)				//cannot insert when found
	{
   		p->value.m_value = value;	//do update when found
    		return true;
	}
    }
    if (!mayInsert)				//not found
	return false;				//cannot update when not found
   
   
						//do insert
    Node* n = new Node;
    n->value.m_key = key;
    n->value.m_value = value;
    n->next = head;
    n->prev = head->prev;
    n->prev->next = n;
    head->prev = n; 
    m_size++;
    
    return true;
}
////////////////////////////////////////////////////////////////////////
// non member functions
////////////////////////////////////////////////////
//combine
	//result might not be empty
	//key in one of m1, m2 --> a pair in result
	//key in both m1 and m2 && v1==v2 --> a pair in result
	//key in both m1 and m2 && v1!=v2 --> return false
	//else return true
//////////////////////////////////////////////////////

bool combine(const Map& m1, const Map& m2, Map& result)	
//past items in m1 and m2(with non contradicted values) into the result
{
	if (&m1==&m2)				//check if m1 m2 are the same
	{	
		result = m1;
		return true;
	}
	////////use only public member of the Map//////////////// //
	KeyType k1,k2;
	ValueType v1,v2; 
	Map temp;				//to avoid aliasing

	bool isTrue = true;
	for (int n1=0; n1<m1.size(); n1++)	//go through items of m1 
	{
		if( m1.get(n1,k1,v1))		
		{
			if ( m2.get(k1,v2)&& v2!=v1)	//if the same key exists in m2 and two values are different
			{	isTrue = false;		
				continue;		//to the next item
			}
			else				//else, insert it into the tempMap
			{
				if(temp.insert(k1,v1))
				{
					cerr<<"inserting "<<k1<<"  of m1 into result..."<<endl; 
				}
			}
		}
	}
	for (int n2=0; n2<m2.size(); n2++)		//go through every items in m2
	{
		if( m2.get(n2,k2,v2))
		{
			if ( m1.get(k2,v1)&& v2!=v1)	//if this key appears in m1 and the value contradicted, do nothing 
				continue;		
			
			else				//else insert this item into tempMap
			{
				if(temp.insertOrUpdate(k2,v2))
				{	
					cerr<<"insert or update "<<k2<<" of m2 into result..."<<endl; 
				}
			}
		}
	}
	result = temp;			
	return isTrue;
}
void subtract(const Map& m1,const Map& m2, Map& result)
	//add those m1 keys, which are not in m2, into result
{
	Map temp;		//to avoid aliasing
	if (&m1==&m2)
	{
		result = temp;	//empty Map 
		return;
	}
	////////////////////use only public member of the Map////////////
	
	KeyType k1;	//,kr;
	ValueType v1;	//,vr;

	for (int n1=0; n1<m1.size(); n1++)		//go through items in m1
	{
		if( m1.get(n1,k1,v1))			//get the key and the value
		{
			if ( m2.contains(k1))		//if the key also exists in m2
				continue;		//jump to next item
			else
			{
				if(temp.insert(k1,v1))	//if not, insert to the temp Map
					cerr<<"inserting"<<k1<<" of m1 into result..."<<endl; 
			}
		}
	}
	result = temp;	
	return;
}
