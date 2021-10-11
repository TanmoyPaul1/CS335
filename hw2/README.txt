/**
 *  Name: Tanmoy Paul
 *  Date: 10/09/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
**/

// Part 1

sequence.h was created with the public functions and private members.

Implemented the Big Five. 

Overloaded comparison operator to check which string comes first.

Added function to check if the recognition_sequence_ is empty. 

Overloaded output operator to later print out all acronyms. 

Added Merge function to put together all the enzyme acronyms
for the same recognition sequences. 


// Part 2A

Edited QueryTree to parse an input file with an ifstream and
extract the recognition sequences and the enzyme acronyms.

Added GetNextRecognitionSequence that created new SequenceMaps 
for each of the lines from the input file. 

Edited QueryTree to get 3 sequences as inputs to check if they
are in the created tree. 

Added print and printHelper functions in the tree files. 

Edited insert in trees files to Merge duplicate sequences.


// Part 2B

Edited test_tree.cc to have GetNextRecognitionSequence and ifstream
functions and code identical to query_tree.cc. 

Added cout statements and calculations to find total nodes,
average depth of nodes, ratios, and all the other required outputs.


// Part 2C

Created avl_tree_mod.h file. 

Changed the doubleWithLeftChild and doubleWithRightChild functions
to manually rotate instead of using the two previous functions.

Copied test_tree.cc to test_tree_mod.cc. 