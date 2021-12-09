/**
 *  Name: Tanmoy Paul
 *  Date: 12/08/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
 * 
 *  This is the graph.h file. 
**/

#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <iostream>
using namespace std;

//This file is for your graph implementation.
//Add everything you need in between the "ifndef and "endif" statements.
//Do not put anything outside those statements

struct Node {   // each connecting node
    int number; 
    double edgeWeight; 
};

struct AdjList {    // each vector of nodes
    vector<Node> list;
};

class Graph { 
public:
    int numVertices_;
    AdjList *adjList_;    // the adjacency list of vectors

    Graph() : numVertices_(0) {}
    
    Graph(int vertices) : numVertices_(vertices) {
        adjList_ = new AdjList[vertices + 1];
    }

    void addEdge(int vertex, int connectedVertex, double weight)
    {
        Node newNode = {connectedVertex, weight};
        adjList_[vertex].list.push_back(newNode);
    }

    void print() {
        cout << "\nGraph: " << endl;
        for(int i = 1; i < numVertices_ + 1; ++i) 
        {
            cout << i << "---> ";
            for(auto &node : adjList_[i].list) 
                cout << node.number << " ";
            cout << endl;
        }
        cout << endl;
    }

    string is_connected(int vertex, int connectedVertex) {
        for(auto &node : adjList_[vertex].list) 
            if (node.number == connectedVertex)
                return "connected " + to_string(node.edgeWeight).substr(0, to_string(node.edgeWeight).find_last_not_of('0') + 1);
        return "not_connected ";
    }

    // ~Graph() { delete adjList_; }
};



#endif