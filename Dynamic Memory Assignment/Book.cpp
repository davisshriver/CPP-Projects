#include <string>
#include <iostream>
#include "Lab 6 - Davis Shriver/Book.h"

using namespace std;

// Default constructor and destructor
Book::Book() {
	cout << "Creating a new book..." << endl;
};
Book::~Book() {
	cout << "In the Book destructor..." << endl;
};

// Getter and setter for book title
void Book::setTitle(std::string t) {
	title = t;
};
std::string Book::getTitle() {
	return title;
};

// Getter and setter for book genre
void Book::setGenre(std::string g) {
	genre = g;
};
std::string Book::getGenre() {
	return genre;
};

//Getter and setter for book type
void Book::setType(std::string t) {
	type = t;
};
std::string Book::getType() {
	return type;
};

//Getter and setter for reading score
void Book::setScore(int s) {
	score = s;
};
int Book::getScore() {
	return score;
};
