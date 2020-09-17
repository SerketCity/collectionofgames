#ifndef NODE_H
#define NODE_H

#include <cstddef>

template<class M>
class Node
{
  private:
    M item;
    Node<M>* nextPtr;

  public:
    Node(M arg_item, Node<M>* arg_nextPtr);
    Node(M arg_item);

    M getItem();
    void setItem(M arg_item);
    Node<M>* getNextPtr();
    void setNextPtr(Node<M>* arg_nextPtr);
};

template<class M>
Node<M>::Node(M arg_item, Node<M>* arg_nextPtr)
{
	item = arg_item;
	nextPtr = arg_nextPtr;
} 

template<class M>
Node<M>::Node(M arg_item)
{
	item = arg_item;
	nextPtr = NULL;
}

template<class M>
M Node<M>::getItem()
{
	return item;
}

template<class M>
void Node<M>::setItem(M arg_item)
{
	item = arg_item;
}

template<class M>
Node<M>* Node<M>::getNextPtr()
{
	return nextPtr;
}

template<class M>
void Node<M>::setNextPtr(Node<M>* arg_nextPtr)
{
	nextPtr = arg_nextPtr;
}

#endif
