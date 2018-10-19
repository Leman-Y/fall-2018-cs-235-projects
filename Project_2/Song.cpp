/*
File's Title: Song.cpp
Author: Leman Yan
Date of creation: 9/21/18
Class: CS 235
Purpose: Project 2 - Make a PlayList

*/


#include "Song.h"

#include <iostream>
#include <vector>

using namespace std;

//Implement constructor and parameterized constructor

//Public


Song::Song()
{
	title_="";
	author_="";
	album_="";
}


Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
	title_=title;
	author_=author;
	album_=album;
}

void Song::setTitle(std::string title)  //"set" in setTitle here means "give a value" and has nothing
				                           // to do with the Set class. Similarly for setAuthor and setAlbum
{
	title_=title;
}

void Song::setAuthor(std::string author)
{
	author_=author;
}

void Song::setAlbum(std::string album)
{
	album_=album;
}

std::string Song::getTitle() const
{
	return title_;
}

std::string Song::getAuthor() const
{
	return author_;
}

std::string Song::getAlbum() const
{
	return album_;
}

/*
Friend functions: Functions that are not members of the class but CAN
access private members of the class
Violates information hiding but can do it if it is appropriate and controlled

This means it doesn't need the scope resolution operator Song::

Checks if two songs have the same title, author , and album name. 
Return: If two songs are the same then return 1 if not return 0
*/
bool operator==(const Song& lhs, const Song& rhs)
{
	if( (lhs.getTitle() == rhs.getTitle()) && (lhs.getAuthor() == rhs.getAuthor()) && (lhs.getAlbum() == rhs.getAlbum()) )
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//Or you can write it like this return ( (lhs.getTitle == rhs.getTitle) && (lhs.getAuthor == rhs.getAuthor) && (lhs.getAlbum == rhs.getAlbum) )
}




