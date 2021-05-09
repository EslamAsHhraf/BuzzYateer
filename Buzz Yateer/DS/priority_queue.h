

#ifndef _priorty_queue
#define _priorty_queue

#include "PriortyNode.h"
#include "priortyQueueADT.h"

using namespace std;


template <typename T>
class priority_queue :public priortyQueueADT<T>
{
private:

	PriortyNode<T>* backPtr;
	PriortyNode<T>* frontPtr;
public:
	priority_queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, int r_priorty);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry )  const;
	~priority_queue();


	priority_queue(const priorty_queue<T> & LQ);
};

template <typename T>
priority_queue<T>::priority_queue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

template <typename T>
bool priority_queue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

template <typename T>
bool priority_queue<T>::enqueue(const T& newEntry,  int r_priorty)
{
	
	PriortyNode<T>* newNodePtr = new PriortyNode<T>(newEntry, r_priorty);
	if (isEmpty())
		frontPtr = newNodePtr;
	else
	{
		
		PriortyNode<T>* ptr = frontPtr;
		if (frontPtr->getPriorty() < newNodePtr->getPriorty())
		{
			newNodePtr->setNext(frontPtr);
			frontPtr = newNodePtr;
		}
		else
		{
			while (ptr->getNext() && ptr->getNext()->getPriorty() > newNodePtr->getPriorty())
			{
				ptr = ptr->getNext();
			}
			newNodePtr->setNext(ptr->getNext());
			ptr->setNext(newNodePtr);
		}
		
	}
	return true;
}

template <typename T>
bool priority_queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PriortyNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	
	frontPtr = frontPtr->getNext();

	if (nodeToDeletePtr == backPtr)
		backPtr = nullptr;


	delete nodeToDeletePtr;

	return true;

}
template <typename T>
bool priority_queue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	
	return true;

}
template <typename T>
priority_queue<T>::~LinkedPriortyQueue()
{
	T temp;


	while (dequeue(temp));
}


template <typename T>
priority_queue<T>::priorty_queue(const priority_queue<T> & LQ)
{
	PriortyNode<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr)
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	PriortyNode<T>* ptr = new PriortyNode<T>(NodePtr->getItem(), NodePtr->getPriorty());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();


	while (NodePtr)
	{
		PriortyNode<T>* ptr = new PriortyNode<T>(NodePtr->getItem(), NodePtr->getPriorty());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePtr = NodePtr->getNext();
	}
}

#endif