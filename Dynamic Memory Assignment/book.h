#pragma once

#include <string>
#include <iostream>

#ifndef Book_H
#define Book_H


// Header class for Vigenere.cpp
class Book {
private:
	std::string title;
	std::string genre;
	std::string type;
	int score;
public:
	// Default constructor and destructor
	Book();
	~Book();

	// Getter and setter for book title
	void setTitle(std::string t);
	std::string getTitle();

	// Getter and setter for book genre
	void setGenre(std::string g);
	std::string getGenre();

	//Getter and setter for book type
	void setType(std::string t);
	std::string getType();

	//Getter and setter for reading score
	void setScore(int s);
	int getScore();


};
#endif
