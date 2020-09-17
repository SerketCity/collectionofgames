#ifndef _LIST_H
#define _LIST_H
#include <iostream>
#include "node.h"
using namespace std;

template <class J>
class LinkedList
{
protected:
  int size;
  Node<J>* frontNodePtr;
  Node<J>* backNodePtr;

public:
  //housekeeping
  LinkedList();
  bool isEmpty();
  int getSize();
  void clear();
  void printList();

  //insertion
  void pushFront(J);
  void pushBack(J);
  void insert(J); //inserts in order
  void insert(int position, J value);

  //deletion
  J popFront();
  J popBack();
  J popAPos(int position);
  void removeVal(J value);

  //static const int ItemNotFound = 8001;
  //static const int IndexOutOfBounds = 8002;
  //static const int ListIsEmpty = 8003;
};


//***************************************
// Function : LinkedList Constructor
// Input: none
// output: none
// Description: sets the variables to null values
//*****************************************
template <class J>
LinkedList<J>::LinkedList()
{
  size = 0;
  frontNodePtr = NULL;
  backNodePtr = NULL;
}

//***************************************
// Function : isEmpty
// Input: none
// output: true/false
// Description: checks if the list is empty.
//*****************************************
template <class J>
bool LinkedList<J>::isEmpty()
{
  if (size < 1)
    return true;
  else
    return false;
}

//***************************************
// Function : getSize
// Input: none
// output: size of the list
// Description: returns the size of the list
//*****************************************
template <class J>
int LinkedList<J>::getSize()
{ return size; }

//***************************************
// Function : clear
// Input: none
// output: none
// Description: clears the list
//*****************************************
template <class J>
void LinkedList<J>::clear()
{
  Node<J>* newNode1 = frontNodePtr; //current
  Node<J>* newNode2 = frontNodePtr->getNextPtr(); //next
  while (newNode2 != NULL) // while newNode1 != backpointer
  {
    newNode1->setNextPtr(NULL);
    delete newNode1;

    newNode1 = newNode2;

    newNode2 = newNode2->getNextPtr();
  } //This loop goes through the list and deletes all of the elements

  newNode1->setNextPtr(NULL);

  backNodePtr = NULL;
  frontNodePtr = NULL;
  size = 0;  //resets the list
  delete newNode1;
  delete newNode2;
}

//***************************************
// Function : printList
// Input: none
// output: none
// Description: prints the list
//*****************************************
template <class J>
void LinkedList<J>::printList()
{
  Node<J>* newNode = frontNodePtr;
  while (newNode != NULL)
  {
    cout << newNode->getItem() << endl;
    newNode = newNode->getNextPtr(); 
  } //loop goes down the list and prints each item
}

//***************************************
// Function : pushFront
// Input: none
// output: none
// Description: Prints the entire list
//*****************************************
template <class J>
void LinkedList<J>::pushFront(J item)
{
  //create a new Node
  Node<J>* newNode = new Node<J>(item, frontNodePtr);
  frontNodePtr = newNode;

  if (isEmpty())
    backNodePtr = newNode;

  size++;

  return;
}

//***************************************
// Function : pushBack
// Input: item
// output: none
// Description: pushes an item to the back of the list
//*****************************************
template <class J>
void LinkedList<J>::pushBack(J item)
{
  //create a new Node
  Node<J>* newNode = new Node<J>(item, NULL);
  if (!isEmpty())
    backNodePtr->setNextPtr(newNode);
  backNodePtr = newNode;

  if (isEmpty())
	  frontNodePtr = newNode; //sets the front to this as well if it's empty

  size++;

  return;
}

//***************************************
// Function : insert
// Input: item
// output: none
// Description: inserts an item behind a bigger item
//*****************************************
template <class J>
void LinkedList<J>::insert(J item)
{
  Node<J>* previous = NULL;
  Node<J>* current = frontNodePtr;
  Node<J>* insertionNode = new Node<J>(item, NULL);

  if (!isEmpty()) //if the list is not empty
  {
    while (item > current->getItem() && current->getNextPtr() != NULL)
    {
      previous = current;
      current = current->getNextPtr();
    } //loops through the list until it finds a spot that the item can load into.

    if (item > current->getItem() && current->getNextPtr() == NULL)
    {
      current = current->getNextPtr();
    } // if the item is the second biggest
    if (current == NULL)
    {
      backNodePtr->setNextPtr(insertionNode);
      backNodePtr = insertionNode;
    } // if the item is the biggest.
    else if (current == frontNodePtr)
    {
      insertionNode->setNextPtr(current);
      frontNodePtr = insertionNode;
    } //if the current node is the front one
    else
    {
      previous->setNextPtr(insertionNode);
      insertionNode->setNextPtr(current);
    }
  }
  else
  {
    frontNodePtr = insertionNode;
    backNodePtr = insertionNode;
  } // add the the list as the only element

  ++size;
  return;
}

//***************************************
// Function : insert(position)
// Input: position, item
// output: none
// Description: inserts an item at a position
//*****************************************
template <class J>
void LinkedList<J>::insert(int position, J item)
{
  //Insert to empty list
  if (isEmpty())
  {
    pushFront(item);
    size++;
    return;
  }

  //Create new Node
  Node<J>* addPtr = new Node<J>(item);
  Node<J>* LoopPtr = frontNodePtr;
  Node<J>* previousPtr = LoopPtr;

  //Adding to an invalid index
  if(position < 0 || position > (size))
  {
    //throw SizeError;
    cout << "Error\n";
  }
  //Adding to the first position
  if(position == 0)
  {
    addPtr->setNextPtr(frontNodePtr);
    frontNodePtr = addPtr;
    size++;
    return;
  }
  //Adding to any position between the first and last

  else if ((position > 0) && (position < size))
  {//Loop to position
    int counter = 0;
    while (counter !=  position)
    {
      previousPtr = LoopPtr;
      LoopPtr = LoopPtr->getNextPtr();
      counter++;
    }
    previousPtr->setNextPtr(addPtr);
    addPtr->setNextPtr(LoopPtr);
    size++;
    return;
  }
  //Adding to the last
  else if (position == size)
  {
    pushBack(item);
    size++;
    return;
  }
}

//***************************************
// Function : popFront
// Input: none
// output: the front item
// Description: returns the front item 
//              and deletes it from the list
//*****************************************
template <class J>
J LinkedList<J>::popFront()
{
  if (isEmpty()) // if the list is empty
  {
	  cout << "List is empty" << endl;
	  throw 7;
  }

  Node<J>* returnNode = frontNodePtr; //set return node equal to front node
  frontNodePtr = frontNodePtr->getNextPtr(); // set the front node as the next node.
  --size;
  return returnNode->getItem(); // returns the item stored at the front.
}

//***************************************
// Function : popBack
// Input: none
// output: back item
// Description: Returns the back item 
//              and removes it from the list.
//*****************************************
template <class J>
J LinkedList<J>::popBack()
{
  Node<J>* tempNode = frontNodePtr;
  Node<J>* returnNode = backNodePtr;
  while (tempNode->getNextPtr() != backNodePtr)
  {
    tempNode = tempNode->getNextPtr();
  }//while the next node is not the back node.

  backNodePtr = tempNode;
  backNodePtr->setNextPtr(NULL);
  returnNode = backNodePtr;
  --size;

  J returnItem = returnNode->getItem();
  return returnItem;
}

//***************************************
// Function : removeVal
// Input: value
// output: none
// Description: removes all instances of the 
//              value from the list
//*****************************************
template <class J>
void LinkedList<J>::removeVal(J value)
{
	Node<J>* current = frontNodePtr;
	Node<J>* previous = NULL;

	if (isEmpty())
	{
		throw 1;
	}

	do
	{
		if (value == current->getItem()) // if the value matches
		{
			if (current == frontNodePtr)
				popFront();
			else if (current == backNodePtr)
				popBack();
			else
			{
				current = current->getNextPtr();
				previous->setNextPtr(current);
				--size;
			} //remove that value
		}
		else
		{
			previous = current;
			current = current->getNextPtr();
		}
	} while (current != NULL); // while previous is the back node.
}

//***************************************
// Function : popAPos
// Input: position
// output: item
// Description: removes and returns an item 
//             at the designated position from the list.
//*****************************************
template <class J>
J LinkedList<J>::popAPos(int position)
{
	Node<J>* current = frontNodePtr;
	Node<J>* previous = NULL;

	if (isEmpty()) //empty
		throw 7;
	if (position > size - 1) // invalid input (greater than the size of the list)
		throw 8;
	if (position < 0) // invalid (less than 0)
		throw 2; 

	for (int x = 0; x < position; x++)
	{
		previous = current;
		current = current->getNextPtr();
	} //loops to position

	if (previous != NULL) // if previous is not an actual pointer.
		previous->setNextPtr(current->getNextPtr());
	if (current == frontNodePtr) // if current is the front
		frontNodePtr = current->getNextPtr();
	if (current == backNodePtr) // if current is the back
		backNodePtr = previous;

	size--;
	return current->getItem();
}

#endif
