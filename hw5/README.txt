/**
 *  Name: Tanmoy Paul
 *  Date: 12/08/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
**/

// Question 1
// File: graph.h

Created Node and AdjList structs with number, weight, and list.

Created Graph class that initialized AdjList graph.

Implemented constructors and destructor. 

Implemented addEdge function to add a new connected vertex to the graph.

Implemented print function to print the graph's vertices and connections.

Implemented is_connected function to return strings of connections for Q1.


// File: CreateGraphAndTest.cc 

Added lambda function to break up inputted file lines.

Implemented while loop to get graph vertices, connections, and weights. 

Used second while loop to vertex connections of the graph and print weights. 


// Question 2
// File: graph.h

Implemented recursion print function to print path values. 

Implemented Dijkstra function using priority queue with BinaryHeap.

Dijkstra function used items in the queue to get minimum vertex number and 
add up costs for the path taken. 

Added for loop to print shortest path values for Q2. 


// File: FindPaths.cc 

Copied code from CreateGraphAndTest.cc and used Dijkstra function on graph. 