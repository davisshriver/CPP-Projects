#pragma once
#include <string>


#ifndef Vigenere_H
#define Vigenere_H


// Header class for Vigenere.cpp
class Vigenere {
private:
	std::string key;
public:
	// Default Constructor
	Vigenere();
	// Constructor that accepts string for key
	Vigenere(std::string k);

	// Getter and setter for "key" string
	void setKey(std::string s);
	std::string getKey();

	// Converts string to all uppercase
	std::string toUpperCase(std::string k);

	//Functions to encrypt and decrypt words
	std::string encrypt(std::string word);
	std::string decrypt(std::string word);

	// Default Destructor
	~Vigenere();




};
#endif
