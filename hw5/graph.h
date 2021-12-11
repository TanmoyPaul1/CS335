/**
 *  Name: Tanmoy Paul
 *  Date: 12/08/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
 * 
 *  This is the graph.h file which implements the adjacency list and Dijkstra algorithm. 
**/

#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <iostream>
#include <limits>
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
    AdjList *paths;
    double distance = numeric_limits<double>::max();
    bool visited = false; 
    int value;
    AdjList(int val) : value(val) {}
};

class Graph { 
public:
    int numVertices_;
    vector<AdjList *> adjList_;    // the adjacency list of vectors

    Graph() : numVertices_(0) {}
    
    Graph(int vertices) : numVertices_(vertices), adjList_(++vertices) {
        for (int i = 1; i <= vertices; ++i)
        {
            adjList_[i] = new AdjList(i);
        }
    }

    void addEdge(int vertex, int connectedVertex, double weight)
    {
        Node newNode{connectedVertex, weight};
        adjList_[vertex]->list.push_back(newNode);
        // cout << newNode.number << " " << newNode.edgeWeight << endl;
    }

    void print() {
        cout << "\nGraph: " << endl;
        for(int i = 1; i < numVertices_ + 1; ++i) 
        {
            cout << i << "---> ";
            for(auto &node : adjList_[i]->list) 
                cout << node.number << " ";
            cout << endl;
        }
        cout << endl;
    }

    // function to print results for Q1: Adjacency
    string is_connected(int vertex, int connectedVertex) {
        for(auto &node : adjList_[vertex]->list) 
            if (node.number == connectedVertex)
                return "connected " + to_string(node.edgeWeight).substr(0, to_string(node.edgeWeight).find_last_not_of('0') + 1);
        return "not_connected ";
    }

    void printPath(AdjList *list)
    {
        if(list->paths != nullptr)  printPath(list->paths);
        cout << list->value << " ";
    }

    // Dijkstra's Algorithm
    void Dijkstra(int starting_vertex)
    {
        BinaryHeap<int> queue; 
        queue.insert(starting_vertex);
        adjList_[starting_vertex]->distance = 0; 
        while (!queue.isEmpty())
        {
            int min_vertex = queue.findMin();
            adjList_[min_vertex]->visited = true; 
            queue.deleteMin();
            for (unsigned int i = 0; i < adjList_[min_vertex]->list.size(); ++i)
            {
                // placeholder variable for each adjList_ number at the minimum vertex
                int num_of_min_vertex = adjList_[min_vertex]->list[i].number;
                double cost = adjList_[min_vertex]->list[i].edgeWeight;
                if (adjList_[min_vertex]->visited == true && adjList_[min_vertex]->distance + cost < adjList_[num_of_min_vertex]->distance)
                {
                    adjList_[num_of_min_vertex]->distance = adjList_[min_vertex]->distance + cost;
                    adjList_[num_of_min_vertex]->paths = adjList_[min_vertex];
                    queue.insert(num_of_min_vertex);
                } 
            }
        }

        //Print shortest_path
        for (int i = 1; i <= numVertices_; i++)
        {
            cout << i << ": ";
            double cost = adjList_[i]->distance;
            
            if (cost != std::numeric_limits<double>::max())
            {
                AdjList *test = adjList_[i];
                printPath(test);
                cout.precision(1);
                cout << fixed << "cost: " << cost << endl;
            }
            else 
                cout << "not_possible" << endl;
        }
    }

    ~Graph() { for (unsigned int i = 0; i < adjList_.size(); ++i)  delete adjList_[i]; }
};



#endif