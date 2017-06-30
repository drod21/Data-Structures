/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 graph.h
 ************************************************************/

#ifndef graph_h
#define graph_h

#include <string>
#include <fstream>
#include "edge.h"
#include "vertex.h"

using namespace std;

#define MAX_GRAPH_SIZE 20

class Graph {
    
public:
	// constructor
	Graph(){

	}

	// destructor
	~Graph(){

	}

	// returns true iff graph is empty
	bool empty(void){

	}

	// returns degree of vertex v
	int degree(string v){

	}

	// returns number of edges in graph
	int edgeCount(void){

	}

	// returns true if graph is connected
	bool isConnected(string u, string v){

	}

	// returns weight of edge connecting vertices u and v
	double adjacent(string u, string v){

	}

	// performs depth first search of graph starting at vertex v
	void DFS(string v){

	}

	// performs breadth first search of graph starting at vertex v
	void BFS(string v){

	}

	// uses Prim's algorithm to show minimum spanning tree of 
	// the vertices that are connected to v
	void MST(string v){

	}

	// builds undirected, weighted graph from data provided in text file
	void buildGraph(){

	}

	// removes all vertices from graph
	void clear(void){

	}

	// marks all vertices as unvisited
	void clearGraph(void){

	}

	// inserts an edge with weight w between vertices u and v
	// if edge already exists, update weight with new w
	void insert(string u, string v, double w){

	}
    
private:
    	// data members
    
    
    
};

#endif /* graph_h */
