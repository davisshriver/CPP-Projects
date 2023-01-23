#include <vector>
#include "Vigenere.h"


#ifndef MyText_H
#define MyText_H

// Header class for MyText.cpp
class MyText {
private:
	int wordsEncrypted;
	int wordsDecrypted;
	std::vector<std::string> words;
	Vigenere v;

public:
	// Default Constructor
	MyText();
	MyText(std::string k);
	// Default Destructor
	~MyText();
	// Encryption and decryption functions
	void encryptWord(char* token);
	void decryptWord(char* token);
	// Creates output file and fills it
	void FileCreate(std::string fileName);
	// Displays the contents of the "words" vector
	void DisplayText();
	// Getter and setter for wordsEncrypted variable
	void setWordsEncrypted(int value);
	int getWordsEncrypted();
	// Getter and setter for wordsDecrypted variable
	void setWordsDecrypted(int value);
	int getWordsDecrypted();
	// These functions increment wordsEncrypted and wordsDecrypted
	void IncWordsEncrypted();
	void IncWordsDecrypted();

	

};
#endif
