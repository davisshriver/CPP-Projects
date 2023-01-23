#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "MyText.h"

using namespace std;

MyText::MyText() {
	wordsEncrypted = 0;
	wordsDecrypted = 0;
}
MyText::MyText(string k) {
	v.setKey(k);
	wordsEncrypted = 0;
	wordsDecrypted = 0;
}
MyText::~MyText() {
	words.clear();
}

// Grabs data character array pointer and encrypts it
void MyText::encryptWord(char* token) {
	string output;
	output = v.encrypt((string)token);
	words.push_back(output);
	IncWordsEncrypted();
}
void MyText::decryptWord(char* token) {
	string output;
	output = v.decrypt((string)token);
	words.push_back(output);
	IncWordsDecrypted();
}

// Create file to output decrypted
void MyText::FileCreate(std::string fileName) {

	// Makes file and copies words from vector into file
	ofstream output(fileName);
	ostream_iterator<string> oi(output, " ");
	copy(words.begin(), words.end(), oi);
	output.close();
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}

// Prints the contents of the the words vector
void MyText::DisplayText() {
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << " ";
	}
	cout << endl << endl;
}

// Getter and setter for wordsEncrypted variable
void MyText::setWordsEncrypted(int value) {
	wordsEncrypted = value;
}
int MyText::getWordsEncrypted() {
	return wordsEncrypted;
}

// Getter and setter for wordsDecrypted varaible
void MyText::setWordsDecrypted(int value) {
	wordsDecrypted = value;
}
int MyText::getWordsDecrypted() {
	return wordsDecrypted;
}

// Increment functions for wordsEncrypted and wordsDecrypted variables
void MyText::IncWordsEncrypted() {
	wordsEncrypted++;
}
void MyText::IncWordsDecrypted() {
	wordsDecrypted++;
}
