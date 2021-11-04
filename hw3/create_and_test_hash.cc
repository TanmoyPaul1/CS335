/**
 *  Name: Tanmoy Paul
 *  Date: 11/04/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
 * 
 *  create_and_test_hash.cc: creates a hash table and finds number of collisions
**/

#include <fstream>
#include <iostream>
#include <string>

// Uncomment when you implemented linear probing & double hashing
#include "linear_probing.h"
#include "double_hashing.h"
#include "quadratic_probing.h"

using namespace std;


// You can add more functions here

// @hash_table: a hash table (can be linear, quadratic, or double)
// @words_filename: a filename of input words to construct the hash table
// @query_filename: a filename of input words to test the hash table
template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
    hash_table.MakeEmpty();    
    ifstream file;
    file.open(words_filename);
    if(file.fail()) cerr << "failed to open " << words_filename << endl;
    string line;
    while(getline(file, line))
    { 
        hash_table.Insert(line);
    }
    file.close();

    cout << "number_of_elements: " << hash_table.numElements() << endl;
    cout << "size_of_table: " << hash_table.tableSize() << endl;
    cout << "load_factor: " << (float) hash_table.numElements() / hash_table.tableSize() << endl;
    cout << "average_collisions: " << (float) hash_table.numCollisions() / hash_table.numElements() << endl;
    cout << "total_collisions: " << hash_table.numCollisions() << endl;
    cout << endl;

    file.open(query_filename);
    if(file.fail()) cerr << "failed to open " << query_filename << endl;
    while(getline(file, line))
    {
	   	hash_table.resetCollisions();
        if(hash_table.Contains(line)) 
            cout << line << " Found " << hash_table.numCollisions() + 1 << endl;        
        else 
            cout << line << " Not_Found " << hash_table.numCollisions() + 1 << endl;
    }
    file.close();
}

// @argument_count: argc as provided in main
// @argument_list: argv as provided in imain
// Calls the specific testing function for hash table (linear, quadratic, or double).
int testHashingWrapper(int argument_count, char **argument_list) {
    const string words_filename(argument_list[1]);
    const string query_filename(argument_list[2]);
    const string param_flag(argument_list[3]);
    int rvalue = 99;
    if (argument_count == 5) {
        const string rvalueparam(argument_list[4]);
        rvalue = stoi(rvalueparam);
    }

    if (param_flag == "linear") {
        // Uncomment below when you have implemented linear probing.
        HashTableLinear<string> linear_probing_table;
        TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);
    } else if (param_flag == "quadratic") {
        HashTable<string> quadratic_probing_table;
        TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);
    } else if (param_flag == "double") {
        cout << "r_value: " << rvalue << endl;
        // Uncomment below when you have implemented double hashing.
        HashTableDouble<string> double_probing_table;
        double_probing_table.rvalue(rvalue);
        TestFunctionForHashTable(double_probing_table, words_filename, query_filename);
    } else {
	cout << "Unknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
    }
    return 0;
}

// Sample main for program create_and_test_hash. DO NOT CHANGE IT.
// WE WILL NOT USE YOUR MAIN IN TESTING. DO NOT CODE FUNCTIONALITY INTO THE
// MAIN. WE WILL DIRECTLY CALL testHashingWrapper. ALL FUNCTIONALITY SHOULD BE
// THERE. This main is only here for your own testing purposes.
int main(int argc, char **argv) {
    if (argc != 4 and argc != 5) {
	cout << "Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag>" << endl;
	cout << "or Usage: " << argv[0]
	     << " <wordsfilename> <queryfilename> <flag> <rvalue>" << endl;
	return 0;
    }

    testHashingWrapper(argc, argv);
    return 0;
}
