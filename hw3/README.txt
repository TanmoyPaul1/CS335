/**
 *  Name: Tanmoy Paul
 *  Date: 11/04/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
**/

// Part 1

Edited quadratic_probing.h to include functions for sizes and collisions

Printed values of the created functions

Opened word and query files

Inserted words into table and checked collisions for query words

Created and implemented linear_probing.h

// Part 2

R = 99

Created and implemented double_hashing.h

Created second hash function for double hashing 
created a function to set the R value 

Printed all required values

// Part 3

Edited spell_check.cc functions

Parsed file to create dictionary

Edited SpellChecker to do the following things:
    -remove non alphanumeric characters from the ends of words
    -make all words lowercase
    -check if the word is in the dictionary
    -if not, then first add every possible letter to every possible position 
    -then, remove a letter from every position
    -finally, swap adjacent letters in the word
    -if any of those steps resulted in a word in the dictionary, then print it 
    -otherwise, only print incorrect
