#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"

using namespace std;

template<class T>
class Stack
{
  protected:
    Node<T>* top;

  public:
    Stack();
    ~Stack();

    bool isEmpty();
    void push(T value);
    T pop();
    T peek();
};

template<class T>
Stack<T>::Stack()
{
  top = NULL;
}

template<class T>
Stack<T>::~Stack()
{
  while(!isEmpty())
  {
    pop();
  }
}

template<class T>
bool Stack<T>::isEmpty()
{
  if(top == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<class T>
void Stack<T>::push(T value)
{
	Node<T>* currentTop = top;
	top = new Node<T>(value, currentTop);
}

template<class T>
T Stack<T>::pop()
{
	if(isEmpty())
	{
		cout<<"Stack is empty!"<<endl;
	}
	else
	{
		Node<T>* tail = top->getNextPtr();
		T result = top->getItem();
		top = tail;
		return result; 
	}
}

template<class T>
T Stack<T>::peek()
{
	if(isEmpty())
	{
		cout<<"Stack is empty!"<<endl;
	}
	else
	{
		return top->getItem();
	}
}

#endif
