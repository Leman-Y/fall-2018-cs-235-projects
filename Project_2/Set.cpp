/*
File's Title: Set.cpp
Author: Leman Yan
Date of creation: 9/21/18
Class: CS 235
Purpose: Project 2 - Make a PlayList

*/


#include <iostream>
#include <vector>

#include "Set.h"


using namespace std;

//Public

//Initialize Constructor

template<class ItemType>
Set<ItemType>::Set()
{
	item_count_=0;
	max_items_=DEFAULT_SET_SIZE;
}


//Implement member functions


/** Gets the current number of entries in this set.

@return The integer number of entries currently in the set. */
template<class ItemType>
int Set<ItemType>::getCurrentSize() const
{
	return item_count_;
}


/** Checks whether this set is empty.

@return True if the set is empty, or false if not. */
template<class ItemType>
bool Set<ItemType>::isEmpty() const
{
	if(item_count_==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/** Adds a new entry to this set.
Set differs from Bag only in the fact that it does not allow duplicates. This means that it does not have a getFrequencyOf()method because an item can be in the Set only once. This also means that add()must check that an element is not in Set already, if it is the item will not be added.

@post  If successful, newEntry is stored in the set and

   the count of items in the set has increased by 1.

@param newEntry  The object to be added as a new entry.

@return  True if addition was successful, or false if not. */
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry)
{
	//Check if the newEntry is in the item array
	for(int i=0; i<max_items_ ; i++)
	{
		if(items_[i]==newEntry)
		{
			return 0;
		}
	}	

	if(item_count_<max_items_)
	{
		items_[item_count_]=newEntry;
		item_count_++;

		return 1;
	}
	else
	{
		return 0;
	}

}

/** Removes a given entry from this set,if possible.

@post  If successful, anEntry has been removed from the set

   and the count of items in the set has decreased by 1.

@param anEntry  The entry to be removed.

@return  True if removal was successful, or false if not. */
// Ex item_count_ is 4 ( 1 2 3 4). The array items starts at 0. 0 1 2 3. Subtract item_count_-1=3. Index of entry is 2. You replace 2 with the last item.

template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry)
{
	int located_index = getIndexOf(anEntry);
	if( (isEmpty() != 1) && (located_index > -1) )
	{
		item_count_--;
		items_[located_index] = items_[item_count_];	
		return 1;
	}	
	else
	{
		return 0;
	}
}


/** Removes all entries from this set.

@post  set contains no items, and the count of items is 0. */
template<class ItemType>
void Set<ItemType>::clear()
{
	item_count_=0;
}




/** Tests whether this set contains a given entry.

@param anEntry  The entry to locate.

@return  True if set contains anEntry, or false otherwise. */

template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}

/** Fills a vector with all entries that are in this set.

@return  A vector containing all the entries in the set. */
template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const
{
	std::vector<ItemType> set_contents;
	for (int i=0; i < item_count_; i++)
	{
		set_contents.push_back(items_[i]);
	}
		return set_contents;
}


//Private
//Implement private member function


template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const
{
	for(int i=0 ; i<item_count_; i++)
	{
		if(items_[i]==target)
		{
			return i;
		}
	}
	return -1;
}

		



