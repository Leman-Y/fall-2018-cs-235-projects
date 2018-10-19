/*
File's Title: PlayList.cpp
Author: Leman Yan
Date of creation: 9/21/18
Class: CS 235
Purpose: Project 2 - Make a PlayList

*/

#include "PlayList.h"

#include <iostream>
#include <vector>

using namespace std;

//Public

//Constructors

PlayList::PlayList()
{
}

PlayList::PlayList(const Song& a_song)
{
	playlist_.add(a_song);

}

//Implement member functions
int PlayList::getNumberOfSongs() const
{
	return playlist_.getCurrentSize(); 
}

bool PlayList::isEmpty() const
{
	return playlist_.isEmpty();
}

bool PlayList::addSong(const Song& new_song)
{
	return playlist_.add(new_song);
}

bool PlayList::removeSong(const Song& a_song)
{
	return playlist_.remove(a_song);
}

void PlayList::clearPlayList()
{
	return playlist_.clear();
}

/*
Going to have to use std::vector<ItemType> Set<ItemType>::toVector() const which Fills a vector with all entries that are in this set and then returns A vector containing all the entries in the set.
*/
void PlayList::displayPlayList() const
{
	vector<Song> listOfSongs = playlist_.toVector(); //Now you have a vector of the songs 
	for( int i=0 ; i < playlist_.getCurrentSize() ; i++)
	{
		cout<<"* Title: "<<listOfSongs[i].getTitle()<<" * Author: "<<listOfSongs[i].getAuthor()<<" * Album: "<<listOfSongs[i].getAlbum()<<" *"<<endl;
	}
	cout<<"End of playlist"<<endl;
}





