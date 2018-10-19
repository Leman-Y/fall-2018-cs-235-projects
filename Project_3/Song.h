/*
File's Title: Song.h
Author: Leman Yan
Date of creation: 9/21/18
Class: CS 235
Purpose: Project 2 - Make a PlayList

*/



#ifndef SONG_H_
#define SONG_H_


#include <iostream>
#include <vector>

class Song
{

	public:

		Song();

		Song(const std::string& title, const std::string& author = "", const std::string& album = "");

		void setTitle(std::string title);  //"set" in setTitle here means "give a value" and has nothing

				                           // to do with the Set class. Similarly for setAuthor and setAlbum

		void setAuthor(std::string author);

		void setAlbum(std::string album);

		std::string getTitle() const;

		std::string getAuthor() const;

		std::string getAlbum() const;

		friend bool operator==(const Song& lhs, const Song& rhs);

	private: 

		std::string title_;

		std::string author_;

		std::string album_;

};
#include "Song.cpp"
#endif 
