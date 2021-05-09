
#ifndef _NODE
#define _NODE
template < class T>
class Node
{
private :
	T item; 
	Node<T>* next; 
public :
	Node()
	{
		
				next = nullptr;
			 
	}
	Node( const T & r_Item)
	{
		item = r_Item;
			next = nullptr;
    } 
	Node( const T & r_Item, Node<T>* nextNodePtr)
	{
		item = r_Item;
		next = nextNodePtr;
	}
	void setItem( const T & r_Item)
	{
		item = r_Item;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}
	T getItem() const 
	{
		return item;
	}

	Node<T>* getNext() const 
	{
		return next;
	}
}; 
#endif
//
//template < class T>
//Node<T>::Node() 
//{
//	next = nullptr;
//} 
//
//template < class T>
//Node<T>::Node( const T& r_Item)
//{
//	item = r_Item;
//	next = nullptr;
//} 
//
//template < class T>
//Node<T>::Node( const T& r_Item, Node<T>* nextNodePtr)
//{
//	item = r_Item;
//	next = nextNodePtr;
//}
//template < class T>
//void Node<T>::setItem( const T& r_Item)
//{
//	item = r_Item;
//} 
//
//template < class T>
//void Node<T>::setNext(Node<T>* nextNodePtr)
//{
//	next = nextNodePtr;
//} 
//
//template < class T>
//T Node<T>::getItem() const
//{
//	return item;
//} 
//
//template < class T>
//Node<T>* Node<T>::getNext() const
//{
//	return next;
//} 