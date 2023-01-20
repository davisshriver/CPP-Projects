// Main.cpp
// CSIS 112-D01
// 1. Assignment Instructions
// 2. https://www.geeksforgeeks.org/creating-array-of-pointers-in-cpp/
// 3. https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Lab 6 - Davis Shriver/Book.h"

using namespace std;

int main() {
	int amount = 0;
	Book** booklist;
	string title, genre, type;
	int score = 0;
	srand((unsigned)100);

	// Intro for student confirmation
	cout << "Davis Shriver - Lab 5" << endl;
	cout << "D01 - Dynamic Memory" << endl << endl;

	// Intro message, gathers amount of books
	cout << "How many books have you read in the last year?" << endl;
	cin >> amount;

	booklist = new Book*[amount];
	cin.ignore();

	// Creating books and storing information
	for (int i = 0; i < amount; i++) {
		booklist[i] = new Book();

		cout << "What is the name of the book?" << endl;
		
		getline(cin, title);
		booklist[i]->setTitle(title);

		cout << "What is the genre of the " << booklist[i]->getTitle() << " book? (Western, Devotional, etc.)" << endl;
		getline(cin, genre);
		booklist[i]->setGenre(genre);

		cout << "What is the type of the book? (Paper, Electronic, etc.)" << endl;
		getline(cin, type);
		booklist[i]->setType(type);

		score = (1 + rand() % 5);
		booklist[i]->setScore(score);

		cout << endl;
	}

	cout << "The are the books you read this year:" << endl;

	// Print books and their info
	for (int i = 0; i < amount; i++) {
		cout << "Book name:           ";
		cout << booklist[i]->getTitle() << endl;

		cout << "Book genre:          ";
		cout << booklist[i]->getGenre() << endl;

		cout << "Book Type:           ";
		cout << booklist[i]->getType() << endl;

		cout << "Reading Score (1-5): ";
		cout << booklist[i]->getScore() << endl << endl;
	}

	// Deleting book objects from the array of Books
	for (int i = 0; i < amount; i++) {
		delete booklist[i];
	}

	// Deleting the array of books
	delete[] booklist;
	return 0;
}
