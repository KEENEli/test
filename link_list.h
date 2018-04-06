#pragma once
#include <iostream>
using namespace std;
#define NULL 0

template<class T>
struct LinklistNode
{
	T _data;
	LinklistNode* _next;
	
	LinklistNode()
		:_next(NULL)
	{}
	
	LinklistNode(const T& data)
		:_data(data),
		_next(NULL)
	{}
};

template<class T>
class Linklist
{
	typedef LinklistNode<T> Node;
public:
	Linklist()
	{
	_head=new Node;	
	}
	
	void rotate()
	{
		Node* ptr=_head->_next;
		
		while(ptr!=NULL&&ptr->_next!=NULL)
		{
			Node* second=ptr->_next;
			ptr->_next=second->_next;
			
			second->_next=_head->_next;
			_head->_next=second;	
		}	
	}
	
	void push_back(const T& data)
	{
		Node* ptr=_head;
		while(ptr->_next!=NULL)
		{
			ptr=ptr->_next;	
		}
		
		//ptr point to the end;
		
		ptr->_next=new Node(data);	
	}
	
	void push_head(const T& data)
	{
		Node* tmp=_head->_next;
		
		_head->_next=new Node(data);
		
		_head->_next->_next=tmp;
	}
	
	bool insert(size_t pos,const T& data)
	{
		int tmp=pos;
		Node* ptr=_head;
		
		while(tmp>1)
		{
		tmp--;
		ptr=ptr->_next;
		if(ptr==NULL)
			return false;	
		}
		
		Node* ptr1=ptr->_next;
		ptr->_next=new Node(data);
		ptr->_next->_next=ptr1;	
		return true;
	}
	
	void print()
	{
		Node* ptr=_head->_next;
		while(ptr)
		{
		cout<<ptr->_data<<" ";
		ptr=ptr->_next;
		}
	}
	
	Node* find_pos(size_t pos)
	{
		int tmp=pos;
		Node* ptr=_head;
		
		while(tmp>0)
		{
		tmp--;
		ptr=ptr->_next;
		if(ptr==NULL)
			return NULL;	
		}
		return ptr;
	}
	
	Node* find_data(const T& data)
	{
		Node* ptr=_head->next;
		while(ptr!=NULL)
		{
			if(data==ptr->_data)
			break;
		}	
		return ptr;
	}
	
	void delete_pos(size_t pos)
	{
		int tmp=pos;
		Node* ptr=_head;
		
		while(tmp>1)
		{
		tmp--;
		ptr=ptr->_next;
		if(ptr==NULL)
			return;	
		}		
		
		Node* ptr1=ptr->_next;
		ptr->_next=ptr->_next->_next;
		
		delete ptr1;	
	}
	
	void delete_data(const T& data)
	{
		Node* prev=_head;
		Node* ptr=_head->_next;
		
		while(ptr)
		{
			if(ptr->_data==data)
			break;
			else
			{
				prev=prev->_next;
				ptr=ptr->_next;	
			}			
		}
		if(ptr==NULL)
		return ;
		
		prev->_next=ptr->_next;
		
		delete ptr;	
		
	}
	
	bool change_pos(size_t pos)
	{
		Node* ptr=find_pos(pos);
		if(ptr==NULL)
			return false;
		else 
			cin>>ptr->_data;	
	}
	
	void sort()
	{
		Node* ptr=_head->_next;
		Node* end=NULL;
		while(ptr!=end)
		{
			while(ptr!=NULL&&ptr->_next!=end)
			{
				if(ptr->_data>ptr->_next->_data)
					swap(ptr->_data,ptr->_next->_data);
			
				ptr=ptr->_next;
			}
		end=ptr;
		ptr=_head->_next;
		}
	}
		
		
	bool empty()
	{
		return _head->_next==NULL;	
	}
	
	void mix(Linklist& list)
	{
		Node* ptr=_head;
		while(ptr->_next!=NULL)	
			ptr=ptr->_next;
			
		ptr->_next=list._head->_next;
	}
protected:
	Node* _head;	
};

