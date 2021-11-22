/**
 *  Name: Tanmoy Paul
 *  Date: 11/19/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
**/

// Question 1
// Step 1: test_sorting_algorithms.cc

Edited VerifyOrder to create a temporary vector sorted by the Comparator, 
then compare it with the original vector to check if it was sorted. 

Implemented GenerateRandomVector to create a vector with random integers.

Implemented GenerateSortedVector to create a sorted vector with random integers.

// Step 2: Sort.h

Edited all sorts to include Comparator in template and parameters. 

Used Comparator to compare values in each sort instead of inequality symbols. 

Implemented sorts in their respective driver functions. 

// Step 3: test_sorting_algorithms.cc

Added print function to test sorting. 

Edited testSortingWrapper to create vectors for each type of sort. Ran all 
sort functions and printed original and sorted vectors. 

// Question 2 

Edited quicksort to take in a function as a parameter. 

Removed unnecessary quicksort driver. 

Added functions for middle and first pivot and edited driver functions 
for quicksort2 and quicksort3 in sort.h. 

Tested quicksort functions and printed results in test_sorting_algorithms.cc.



Testing: 

./test_sorting_algorithms random 10 greater
./test_sorting_algorithms random 10 less
./test_sorting_algorithms sorted_small_to_large 10 greater
./test_sorting_algorithms sorted_large_to_small 10 less
