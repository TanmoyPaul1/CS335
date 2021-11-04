/**
 *  Name: Tanmoy Paul
 *  Date: 11/04/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
 * 
 *  spell_check.cc: A simple spell checker.
**/

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

// You can change to quadratic probing if you
// haven't implemented double hashing.
#include "double_hashing.h"
#include "quadratic_probing.h"
#include "linear_probing.h"
using namespace std;

// You can add more functions here.

// Creates and fills double hashing hash table with all words from
// dictionary_file
HashTableDouble<string> MakeDictionary(const string &dictionary_file) {
  HashTableDouble<string> dictionary_hash;
  // Fill dictionary_hash.
  ifstream file;
  file.open(dictionary_file);
  if(file.fail()) cerr << "failed to open " << dictionary_file << endl;
  string line;
  while(getline(file, line))
  { 
    dictionary_hash.Insert(line);
  }
  file.close();
  return dictionary_hash;
}

// For each word in the document_file, it checks the 3 cases for a word being
// misspelled and prints out possible corrections
void SpellChecker(const HashTableDouble<string>& dictionary, const string &document_file) {
  ifstream file;
  file.open(document_file);
  if(file.fail()) cerr << "failed to open " << document_file << endl;
  string word;
  while(file >> word)
  {
    for(size_t i = word.length() - 1; i >= 0; ++i)
    {
      if(!isalnum(word[i])) word = word.substr(0, i);
      else break;
    }

    // lowercase
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (dictionary.Contains(word))
    { 
      cout << word << " is CORRECT" << endl;
    }
    else
    {
      cout << word << " is INCORRECT" << endl;
      string alphabet = "abcdefghijklmnopqrstuvwxyz";
      for (size_t i = 0; i < word.length(); ++i)
      {
        for(char c : alphabet) 
        {
          string result = word.substr(0, i) + c + word.substr(i);
          if (dictionary.Contains(result))
          {
            cout << "*** " << word << " -> " << result << " *** case A" << endl;
          }
        }
      }
      for(char c : alphabet) 
      {
        string result = word.substr(0, word.length()) + c;
        if (dictionary.Contains(result))
        {
          cout << "*** " << word << " -> " << result << " *** case A" << endl;
        }
      }

      for (size_t i = 0; i < word.length(); ++i)
      {
        string result = word;
        result = result.erase(i, 1);
        if (dictionary.Contains(result))
        {
          cout << "*** " << word << " -> " << result << " *** case B" << endl;
        }
      }
      for (size_t i = 0; i < word.length() - 1; ++i)
      {
        string result = word;
        char c = result[i];
        result[i] = result[i + 1];
        result[i + 1] = c;
        if (dictionary.Contains(result))
        {
          cout << "*** " << word << " -> " << result << " *** case C" << endl;
        }
      }
    }
  }
  file.close();
}

// @argument_count: same as argc in main
// @argument_list: save as argv in main.
// Implements
int testSpellingWrapper(int argument_count, char** argument_list) {
    const string document_filename(argument_list[1]);
    const string dictionary_filename(argument_list[2]);

    // Call functions implementing the assignment requirements.
    HashTableDouble<string> dictionary = MakeDictionary(dictionary_filename);
    SpellChecker(dictionary, document_filename);

    return 0;
}

// Sample main for program spell_check.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testSpellingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char** argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>"
         << endl;
    return 0;
  }
  
  testSpellingWrapper(argc, argv);
  
  return 0;
}
