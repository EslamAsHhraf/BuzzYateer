
#ifndef Priorty_Node
#define Priorty_Node
template < class T>
class PriortyNode
{
private:
	int priorty;
	T item;
	PriortyNode<T>* next;
public:
	PriortyNode();
	PriortyNode(const T  r_Item, int  r_priorty);
	PriortyNode(const T & r_Item, int & r_priorty,PriortyNode<T>* nextNodePtr);
	void setItem(const T & r_Item);
	void setPriorty(const T &r_priorty);
	int getPriorty()const;
	void setNext(PriortyNode<T>* nextNodePtr);
	T getItem() const;
	PriortyNode<T>* getNext() const;
};
#endif

template < class T>
PriortyNode<T>::PriortyNode()
{
	next = nullptr;
}

template < class T>
PriortyNode<T>::PriortyNode(const T  r_Item, int  r_priorty)
{
	item = r_Item;
	priorty = r_priorty;
	next = nullptr;
}

template < class T>
PriortyNode<T>::PriortyNode(const T& r_Item, int & r_priorty,PriortyNode<T>* nextNodePtr)
{
	item = r_Item;
	priorty = r_priorty;
	next = nextNodePtr;
}
template < class T>
void PriortyNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}
template < class T>
void PriortyNode<T>::setPriorty(const T &r_priorty)
{
	priorty = r_priorty;
}
template < class T>
void PriortyNode<T>::setNext(PriortyNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template < class T>
T PriortyNode<T>::getItem() const
{
	return item;
}

template < class T>
int  PriortyNode<T>::getPriorty() const
{
	return priorty;
}

template < class T>
PriortyNode<T>* PriortyNode<T>::getNext() const
{
	return next;
}