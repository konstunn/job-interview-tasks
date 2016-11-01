
#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <ostream>

template <class T> class List;

template <class T> 
class Node 
{
	T _data;
	Node <T> *_pNext;

	public:

	const T & getData() const { return _data; }

	Node <T> * getNext() const { return _pNext; }

	void setNext (Node <T> * pNext) { _pNext = pNext; }

	Node () : _pNext (NULL) {}	

	Node (T data, Node <T> *pNext) : _data (data), _pNext (pNext) {}

	friend class List <T>;
};

template <class T>
class List
{
	Node <T> * _pHead;

	Node <T> ** getAfterLast (Node <T> ** curr) 
	{
		Node <T> ** i;
		for (i = curr; *i != NULL; i = &((*i)->_pNext));
		return i;
	}

	public:

	List () : _pHead (NULL) {}

	List (T* a, const int N) : List() 
	{
		if (NULL == a)
		  return;

		Node <T> ** curr = & _pHead;

		for (int i = 0; i < N; ++i)
		{
			*curr = new Node <T> (a[i], NULL);
			curr = getAfterLast (curr);
		}
	}

	~List ()
	{
		Node <T> * curr = _pHead;			
		Node <T> * prev;
		while (NULL != curr)
		{
			prev = curr;
			curr = curr->getNext();
			delete prev;
		}
	}

	void push_back (T & data)
	{
		Node <T> ** last = getAfterLast (& _pHead); 
		*last = new Node <T> (data, NULL);
	}
	
	List <T> & reverse ()
	{
		Node <T> *prev = NULL;
		Node <T> *next;

		for (Node <T> *curr = _pHead; curr != NULL; prev = curr, curr = next)
		{
			next = curr->getNext();		
			curr->setNext (prev);
		}
		_pHead = prev;
		return *this;
	}
	
	friend std::ostream & operator << (
	std::ostream & stream, 
	const List <T> & list)
	{
		Node <T> * p = list._pHead;

		stream << "{";

		while (NULL != p)
		{
			stream << p->getData();
			p = p->getNext();
			if (NULL != p) 
				stream << ", "; 
		}

		stream << "}";
		return stream;
	}
};

#endif
