/**
 *  Name: Tanmoy Paul
 *  Date: 12/08/2021
 *  Professor: Ionnis Stamos
 *  Class: CSCI 335
 * 
 *  This is the CreateGraphAndTest.cc file which creates the graph and prints adjacencies. 
**/

#include "graph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int graphTestDriver(int argc, char **argv) {
    
    //Begin your code here. Feel free to add any helper functions or classes you need,
    //as long as we only have to call this function to run the specified assignment.

	// lambda function to break apart string line
	auto next_num = [&]( string &line, string &str)
	{
		str = line.substr(0, line.find(" "));
		line = line.substr(line.find(" ") + 1); 
	};

	const string graph_filename(argv[1]);
	const string adjacency_filename(argv[2]);

	// open the graph file
	ifstream input_file(graph_filename);
	if (!input_file.good())		// check file
	{
		cerr << "Error reading file" << endl;
		exit(1);
	}

	string line;
	getline(input_file, line);
	// create graph with the number of vertices
	Graph graph(stoi(line));
	string str;
	while (getline(input_file, line)) {
		// obtain vertex
		next_num(line, str);
		int vertex = stoi(str);
		int connected;
		double weight;
		while (line.find(" ") != string::npos)
		{	
			// obtain connected vertex and weight
			next_num(line, str);
			connected = stoi(str);
			next_num(line, str);
			weight = stod(str);
			// cout << vertex << " " << connected << " " << weight << endl;
			graph.addEdge(vertex, connected, weight);
		}		
	}
	// graph.print();
	input_file.close();

	// open the adjacency file
	input_file.open(adjacency_filename);
	while (getline(input_file, line)) {
		next_num(line, str);
		int vertex = stoi(str);
		next_num(line, str);
		int connected = stoi(str);
		cout << vertex << " " << connected << ": ";
		cout << graph.is_connected(vertex, connected) << endl;
	}
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
