#include <iostream>
#include <fstream>
#include <string>
#include <cctype>      // for tolower, toupper
#include <sstream>     // for counting words
#include <algorithm>   // for reverse
using namespace std;

// Function required by the question (v)
string Reverse(string text) {
    reverse(text.begin(), text.end());
    return text;
}

// Helper function: capitalize the second letter of every word
string capitalizeSecondLetter(string text) {
    bool newWord = true;
    int letterCount = 0;

    for (size_t i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            letterCount++;
            if (letterCount == 2) {          // second letter of the word
                text[i] = toupper(text[i]);
            }
        }
        else {
            // space or punctuation → next alphabetic character starts a new word
            letterCount = 0;
        }
    }
    return text;
}

int main() {
    // (ii) Open the file and store contents in fileData 
    ifstream file("data.txt");
    string fileData;

    if (!file.is_open()) {
        cout << "Error: Could not open data.txt" << endl;
        return 1;
    }

    // Read the entire line into fileData
    getline(file, fileData);
    file.close();

    cout << "Original text from file:\n" << fileData << endl << endl;

    // (iii) Count the number of vowels
    int vowelCount = 0;
    for (char c : fileData) {
        char lower = tolower(c);
        if (lower == 'a' || lower == 'e' || lower == 'i' ||
            lower == 'o' || lower == 'u') {
            vowelCount++;
        }
    }
    cout << "Number of vowels: " << vowelCount << endl;

    //(iv) Count the number of words
    int wordCount = 0;
    stringstream ss(fileData);
    string word;
    while (ss >> word) {
        wordCount++;
    }
    cout << "Number of words: " << wordCount << endl << endl;

    // (v) Reverse the statement using the Reverse function 
    string reversed = Reverse(fileData);
    cout << "Reversed statement:\n" << reversed << endl << endl;

    // (vi) Capitalize the second letter of each word 
    string result = capitalizeSecondLetter(fileData);
    cout << "Statement with second letter of each word capitalized:\n"
         << result << endl;

    return 0;
}