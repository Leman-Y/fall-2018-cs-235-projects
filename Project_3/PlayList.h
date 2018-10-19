/*
File's Title: PlayList.h
Leman Yan
Class:CS_235
Professor: Tiziana Ligorio
Date of creation: 10/3/18
Purpose: Project 3 - Make a Playlist based off of a Linked Chain (Linked Nodes) & Retain Order
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_	//Header guard to not compile more 1 time

#include "LinkedSet.h"  //include linkedset
#include "Song.h"



class PlayList : public LinkedSet<Song>
{
public:
//PlayList constructors need to make sure to correctly initialize the derived class private data members (tail_ptr_). 
	PlayList();                     //default constructor

	//Using Song& passing by reference not value so its memory efficient. When you dont include & ur passing by value. You wont be able to change the variable
	PlayList(const Song& a_song);   //parameterized constructor

	PlayList(const PlayList& a_play_list); // copy constructor

	~PlayList(); // Destructor

    bool add(const Song& new_song) override;

    bool remove(const Song& a_song) override;

	//Make the last node point to the first node
    void loop();
   
	//Revert the last node by making it point to nullptr
    void unloop();

	//make a vector and print out title, author, album for loop
    void displayPlayList();



private:
	Node<Song>* tail_ptr_; // Pointer to last node

 	//Helper functions

	//Returns pointer to the last node
	Node<Song>* getPointerToLastNode() const;

	//Points to the node that contains the target
    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;

};
//#include "PlayList.cpp"
#endif




