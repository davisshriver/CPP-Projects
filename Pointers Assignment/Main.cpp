// Main.cpp
// CSIS 112-D01
// 1. Assignment Instructions
// 2. https://www.geeksforgeeks.org/convert-string-char-array-cpp/#:~:text=1.-,Using%20c_str()%20with%20strcpy(),()%20functions%20of%20library%20cstring.
// 3. https://en.cppreference.com/w/cpp/iterator/ostream_iterator
// 4. https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
// 5. https://www.youtube.com/watch?v=u5AH2Wn6h1o
// 6. https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?redirectedfrom=MSDN&view=msvc-170

#include "MyText.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

int displayMenu();
void encryptArr(string key, char k[]);
void decryptArr(string key, char k[]);

int main() {
	char contents[1000];
	string key, fileName, temp, curr;
	int selection = 0;

	cout << "Davis Shriver - Lab 5" << endl;
	cout << "D01 - Pointers Assignment" << endl << endl;

	while (selection != 3) {
		
		selection = displayMenu();
		

		// Encrypt
		if (selection == 1) {
			cout << "Enter an encryption key: " << endl;
			cin.ignore();
			getline(cin, key);

			cout << "Enter the name of the file to encrypt: ";
			getline(cin, fileName);
			cout << endl;

			// Create File
			ifstream in(fileName);

			while (getline(in, curr)) {
				temp += curr;
				temp.push_back('\n');
			}
			
			// Copy string to character array
			for (int k = 0; k < temp.size(); k++) {
				contents[k] = temp[k];
			}

			// Prints the character array "contents"
			for (int j = 0; j < temp.size(); j++) {
				cout << contents[j];
			}
			temp.clear();
			// Start tokenization and encryption
			encryptArr(key, contents);
			in.close();
		}
		// Decrypt
		else if (selection == 2) {
			cout << "Enter an encryption key: " << endl;
			cin.ignore();
			getline(cin, key);

			cout << "Enter the name of the file to decrypt: ";
			getline(cin, fileName);
			cout << endl;

			// Open file 
			ifstream din(fileName);

			while (getline(din, curr)) {
				temp += curr;
				temp.push_back('\n');
			}


			// Copy string to character array
			for (int k = 0; k < temp.size(); k++) {
				contents[k] = temp[k];
			}
			// Prints the character array "contents"
			for (int j = 0; j < temp.size(); j++) {
				cout << contents[j];
			}
			temp.clear();
			// Start tokenization and decryption
			decryptArr(key, contents);
			din.close();
		}
		// Quit
		else if (selection == 3) {
			return 0;
		}
		else
		{
			cout << endl;
			cout << "Please enter a valid value!" << endl << endl;
		}
	}
	// Exit program
	return 0;
}

int displayMenu() {
	int s = 0;
	// Main Menu Display and Input Retrieval
	cout << "  Vigenere Cypher" << endl << endl;
	cout << "     Main Menu" << endl << endl;
	cout << "  1 - Encrypt File" << endl;
	cout << "  2 - Decrypt File" << endl;
	cout << "  3 - Quit" << endl;
	cout << "  Selection: ";
	cin >> s;

	// Checking for invalid or nonnumeric input
	if (!cin >> s) {
		cin.clear();
		cin.ignore(100, '\n');
	}
	return s;
}
// Function that handles tokenization, encryption, and file output. (Implemented for cleanliness)
void encryptArr(string key, char k[]) {
	string fileName;
	char* token1;
	char* token2 = NULL;
	char del[] = " ";
	MyText M(key);

	// Grab first word
	token1 = strtok_s(k, del, &token2);

	// Grab to rest of the words and encrypt them
	while (token1 != NULL) {
		M.encryptWord(token1);
		token1 = strtok_s(NULL, del, &token2);
	}
	cout << endl;
	cout << "A new file will be created that contains the encrypted message." << endl;
	cout << "Please enter the name of the new file to create: ";
	getline(cin, fileName);
	cout << endl;

	cout << "The new file contains the encrypted message." << endl << endl;
	M.DisplayText();
	cout << "The message contained " << M.getWordsEncrypted() << " words." << endl << endl;
	// Create output file
	M.FileCreate(fileName);
}

// Function that handles tokenization, decryption, and file output. (Implemented for cleanliness)
void decryptArr(string key, char k[]) {
	string fileName;
	char* token1;
	char* token2 = NULL;
	char del[] = " ";
	MyText M(key);

	// Grab first word
	token1 = strtok_s(k, del, &token2);

	// Grab to rest of the words and decrypt them
	while (token1 != NULL) {
		M.decryptWord(token1);
		token1 = strtok_s(NULL, del, &token2);
	}
	cout << endl;
	cout << "A new file will be created that contains the decrypted message." << endl;
	cout << "Please enter the name of the new file to create: ";
	getline(cin, fileName);
	cout << endl;

	cout << "The new file contains the decrypted message." << endl << endl;
	M.DisplayText();
	cout << "The message contained " << M.getWordsDecrypted() << " words." << endl << endl;

	// Create output file
	M.FileCreate(fileName);
}
