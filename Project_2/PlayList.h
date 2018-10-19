/*
File's Title: PlayList.h
Author: Leman Yan
Date of creation: 9/21/18
Class: CS 235
Purpose: Project 2 - Make a PlayList

*/


#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include "Set.h"
#include "Song.h"

#include <iostream>
#include <vector>

class PlayList
{

	public: 
		//Constructors
		PlayList();

		PlayList(const Song& a_song);

		//Member Functions
		int getNumberOfSongs() const;

		bool isEmpty() const;

		bool addSong(const Song& new_song);

		bool removeSong(const Song& a_song);

		void clearPlayList();

		void displayPlayList() const;

	private:
		Set<Song> playlist_;
};
#endif
		

