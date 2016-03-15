#include "BinaryFile.h"
#include <cstring>

struct DiskNode	//each node take 16 bit
{
	DiskNode(){};
	DiskNode(std::string name) 
	:m_next(0)
	{
		m_offset=0;
		m_next=0;
		m_name[7]='\0';
		strcpy(m_name,name.c_str());
	} 
	char m_name[7+1];	//take 8 bit, includes one for 0
	BinaryFile::Offset m_next;	//take 4 bit, the next position, can be the result after hashFunction
	BinaryFile::Offset m_offset;	//offset of itself
};



struct DiskList	//a linked list using array addreses
{
	DiskList(const std::string& fileName)
	{
		currOffset=0;
		unitOffset=30;
		bool success = bf.createNew(fileName);
		if (success)
			cerr<<"Successfully created file "<<fileName<<endl;
		else
		{
			success = bf.openExisting(fileName);
			if (success)
				cerr<<"Successfully opened existing file "<<fileName<<endl;
			else
				cerr<<"Error, unable to create or open file "<<fileName<<endl;
		}
		DiskNode headNode("Head");
		bf.write(headNode,currOffset);	//write 0 as head in the front of the data
	};

	void push_front(DiskNode newNode)
	{
		newNode.m_next=currOffset;
		currOffset+=unitOffset;
		newNode.m_offset=currOffset;
		headNode.m_next=currOffset;
		if(!bf.write(newNode,currOffset))
		{	cerr<<"Error writing DiskNode to file!"<<endl;
			currOffset-=unitOffset;
			headNode.m_next=currOffset;
		}
		else
		{	
			cerr<<"write in "<<newNode.m_name<<" at "<<currOffset<<endl;
			cerr<<"it points to "<<newNode.m_next<<endl;
		}
	};
	void remove(string targetName)
	{
		DiskNode ThisNode = headNode;
		DiskNode NextNode = headNode;
		while(ThisNode.m_next!=0)
		{	
			if(!bf.read(NextNode,ThisNode.m_next))
			{	cout<<"having trouble reading next DiskNode."<<endl;
				return;
			}
			if(strcmp(NextNode.m_name,targetName.c_str())==0)
			{	
				ThisNode.m_next=NextNode.m_next;
				if(!bf.write(ThisNode,ThisNode.m_offset))
				{	cerr<<"Error updating data"<<endl;
					return;
				}
				//will not read this node again, but the data is left there, waiting to be covered
			}
			//move to next
			else
				bf.read(ThisNode,ThisNode.m_next);		
		}
	};
	void printLastNode()
	{
		DiskNode ThisNode;
		bf.read(ThisNode, currOffset);
		cout<<"The Last Node is "<<ThisNode.m_name<<endl;
		cout<<"The Last Node points to "<<ThisNode.m_next<<endl;
		BinaryFile::Offset offset;
		if(!bf.read(offset,currOffset+8))
			cerr<<"Error reading offset"<<endl;
		else
			cerr<<"assure that the last node points to "<<offset<<endl;
	};
	void printSecondLastNode()
	{
		DiskNode ThisNode;
		bf.read(ThisNode, currOffset-unitOffset);
		cout<<"The Second Last Node is "<<ThisNode.m_name<<endl;
		cout<<"The Second Last Node points to "<<ThisNode.m_next<<endl;
		BinaryFile::Offset offset;
		if(!bf.read(offset,currOffset-unitOffset+8))
			cerr<<"Error reading offset"<<endl;
		else
			cerr<<"assure that the second last node points to "<<offset<<endl;
	};


	void printAll()
	{
		
		DiskNode ThisNode=headNode;
//		cerr<<"The HeadNode is pointing to "<<headNode.m_next<<endl;
		
		while(ThisNode.m_next!=0)
		{
			if(ThisNode.m_offset==0 && bf.read(ThisNode,ThisNode.m_next))
				continue;
			cerr<<ThisNode.m_name<<endl;
//			cerr<<" and the next node is at "<<ThisNode.m_next<<endl;
			if(!bf.read(ThisNode,ThisNode.m_next))
				cerr<<"cannot read next node"<<endl;
		}
		cout<<ThisNode.m_name<<endl;
	};
 private: 
	BinaryFile bf;
	//DiskNode someStructure[100];
	DiskNode headNode;
	BinaryFile::Offset unitOffset;
	BinaryFile::Offset currOffset;	//point to the last DiskNode		
};
