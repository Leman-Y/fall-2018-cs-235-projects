//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2018

//A Node object for building chains with a data member and a pointer to the next node
/** @file Node.h 
    Listing 4-1 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType        item_; // A data item
   Node<ItemType>* next_; // Pointer to next node
   
public:
   Node();  //default constructor		//set next_ to nullptr. item_ is empty by default
   Node(const ItemType& an_item);   //parameterized constructor		//New node set item_=an_item, next_=nullptr
   Node(const ItemType& an_item, Node<ItemType>* next_node_ptr);//parameterized constructor
   
    //post: gives a value to the data member
   void setItem(const ItemType& an_item);
    
   //post: gives a value to the pointer member
   void setNext(Node<ItemType>* next_node_ptr);

   //return: the data member
   ItemType getItem() const ;
    
   //return: the pointer to the next node
   Node<ItemType>* getNext() const ;
    
}; // end Node

#include "Node.cpp"
#endif
