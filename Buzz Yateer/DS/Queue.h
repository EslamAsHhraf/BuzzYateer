

#ifndef _queue
#define _queue

#include "Node.h"
#include "QueueADT.h"

using namespace std;


template <typename T>
class queue:public QueueADT<T>
{
private :
	
	Node<T>* backPtr;
	Node<T>* frontPtr;
public :
	queue();
	bool isEmpty() const ;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);  
	bool peek(T& frntEntry)  const;	
	~queue();

	
	queue(const queue<T> & LQ);
};

template <typename T>
queue<T>::queue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}

template <typename T>
bool queue<T>::isEmpty() const
{
	return (frontPtr==nullptr);
}

template <typename T>
bool queue<T>::enqueue( const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	
	if (isEmpty())	
		frontPtr = newNodePtr; 
	else
		backPtr->setNext(newNodePtr); 

	backPtr = newNodePtr; 
	return true ;
} 

template <typename T>
bool queue<T>:: dequeue(T& frntEntry)
{
	if(isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	
	if (nodeToDeletePtr == backPtr)	 
		backPtr = nullptr ;	
		
	
	delete nodeToDeletePtr;

	return true;

}
template <typename T>
bool queue<T>:: peek(T& frntEntry) const
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
template <typename T>
queue<T>::~LinkedQueue()
{
	T temp;
	
	
	while(dequeue(temp));	
}


template <typename T>
queue<T>::queue(const queue<T> & LQ)
{	
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) 
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}	
}

#endif