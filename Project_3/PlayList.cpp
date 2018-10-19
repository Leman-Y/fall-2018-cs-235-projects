/*
File's Title: PlayList.cpp
Leman Yan
Class:CS_235
Professor: Tiziana Ligorio
Date of creation: 10/3/18
Purpose: Project 3 - Make a Playlist based off of a Linked Chain (Linked Nodes) & Retain Order
*/

#include "PlayList.h"

#include <iostream>
#include <vector>

using namespace std;


// 									public

//PlayList constructors need to make sure to correctly initialize the derived class private data members (tail_ptr_). 
PlayList::PlayList()
{
	tail_ptr_=nullptr;
}

PlayList::PlayList(const Song& a_song)   //parameterized constructor
{
	add(a_song);
}


//Not sure how I can make my copy constructor simpler, instead of copying the entire copy contructor of LinkedSet
PlayList::PlayList(const PlayList& a_play_list):LinkedSet(a_play_list)
{
	tail_ptr_=a_play_list.getPointerToLastNode();


}


//Deletes all the dynamically allocated Nodes and set the ptrs to nullptrs
PlayList::~PlayList() // Destructor 
{
	unloop();
	clear();
}




/*
A PlayList is like a Set in that you don't want to have the same song play multiple times.
It would be nice, however, to add songs at the end of the PlayList instead of adding at the beginning like Set does. So you decide to override add() to do just that.
Just as in Set you always have access to the first node through head_ptr_ . Conveniently, in PlayList you also always have access to the last node through its  tail_ptr_private data member. 
As you write this function makes sure you add correctly when the PlayList is empty as well. 
Test both cases, and make sure both head_ptr_ and tail_ptr point to the correct node at the end of this operation.
*/

bool PlayList::add(const Song& new_song)	//Implementation does not need virtual or overide keyword
{
	tail_ptr_=getPointerToLastNode();

	//Empty PlayList
	if(isEmpty()==1)
	{
		Node<Song>* node_ptr = new Node<Song>(new_song);
		head_ptr_ =node_ptr;
		tail_ptr_=node_ptr;
		item_count_++;

		return true;
	}

	//Not empty PlayList. Add to the end
	if(!contains(new_song))	//No duplicates
	{
		Node<Song>* node_ptr = new Node<Song>(new_song);
		tail_ptr_->setNext(node_ptr);
		tail_ptr_=node_ptr;
		item_count_++;
		return true;
	}
	else
	{
		return false;
	}

}



/*
Another thing that bothers you about your current implementation of PlayList is that removing a Song does not retain the order in which you added Songs to your PlayList. 
So you will override remove() to preserve the order of the Songs.
To do this, you will implement your own private member function getPointerTo which will return a pointer to the item you want to delete.
This function will also have a reference parameter  previous_ptr which will be set to point to the node preceding the one you want to remove. This will be useful to retain the order in the chain. 
So remove will call getPointerTo and using both pointers it will be able to delete a node while preserving the order and keeping the chain connected.
Keep in mind that remove is public while getPointerTo is private (a helper function)
*/

bool PlayList::remove(const Song& a_song)
{
	//If is empty
	if(isEmpty()==1)
	{
		return 0;
	}
	if(!contains(a_song))
	{
		return 0;
	}
	//If only one node
	if(head_ptr_==tail_ptr_)
	{

		Node<Song>* node_to_delete_ptr = head_ptr_;
		node_to_delete_ptr->setNext(nullptr);
		delete node_to_delete_ptr;
		node_to_delete_ptr=nullptr;
		item_count_--;
		return 1;
	}


	//More than one song and contains it
	else
	{
		
		Node<Song>* previous_pointer;
		Node<Song>* target_ptr=getPointerTo(a_song,previous_pointer);
		//If deleting first node
		if(target_ptr==head_ptr_)
		{
			head_ptr_=head_ptr_->getNext();
			target_ptr->setNext(nullptr);
			delete target_ptr;
			target_ptr=nullptr;
			item_count_--;
			return 1;
		}

		//If you are deleting the last node then you need to reset tailptr
		if(target_ptr==tail_ptr_)
		{
			previous_pointer->setNext(target_ptr->getNext());		
			delete target_ptr;
			target_ptr=nullptr;
			item_count_--;
			tail_ptr_=previous_pointer;
			return 1;
		}
			
		//If not the last node then you do not need to worry
		else
		{
			previous_pointer->setNext(target_ptr->getNext());		
			delete target_ptr;
			target_ptr=nullptr;
			item_count_--;
			return 1;
		}

	}

}

//Make the last node point to the first node
void PlayList::loop()
{
	tail_ptr_->setNext(head_ptr_);
}

//Revert the last node by making it point to nullptr
void PlayList::unloop()
{
	tail_ptr_->setNext(nullptr);
}


//make a vector and print out title, author, album for loop
void PlayList::displayPlayList()
{

	vector<Song> listOfSongs = toVector();
	for(int i=0 ; i < getCurrentSize() ; i++)
	{
		cout<<"* Title: "<<listOfSongs[i].getTitle()<<"* Author: "<<listOfSongs[i].getAuthor()<<"* Album: "<<listOfSongs[i].getAlbum()<<" *"<<endl;
	}
	cout<<"End of playlist"<<endl;

}

//								private


Node<Song>* PlayList::getPointerToLastNode() const
{
	Node<Song>* ptr_to_last;
	ptr_to_last=head_ptr_;
	if(head_ptr_ == nullptr)
	{
		return head_ptr_;
	}
	
	for(int i=0 ; i < item_count_-1 ; i++)
	{
		ptr_to_last=ptr_to_last->getNext();

	}
	return ptr_to_last;

}



//return a pointer to the item you want to delete and previous_ptr which will be set to point to the node preceding the one you want to remove
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const
{
	bool found = false;
	Node<Song>* cur_ptr;
	previous_ptr = head_ptr_; 

	while (!found && (cur_ptr != nullptr))
	{
		//Need to check if the first node is the target
		if( target == previous_ptr->getItem() )
		{
			previous_ptr=nullptr;
			cur_ptr=head_ptr_;
			return cur_ptr;
		}

		if (target == previous_ptr->getNext()->getItem())		//Need to be one node away from target node
		{	
			cur_ptr=previous_ptr->getNext(); 			
			found = true;
		}
		else
		{
			previous_ptr = previous_ptr->getNext();			//If not found move through the chain
		}
	
	}  

	return cur_ptr;

}













