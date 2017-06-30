/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 dirGraph.h
 ************************************************************/

#ifndef dirGraph_h
#define dirGraph_h

#include <string>
#include <fstream>
#include "edge.h"
#include "vertex.h"

using namespace std;

#define MAX_DIRGRAPH_SIZE 20

class DirGraph {
    
public:
	// constructor
	DirGraph(){

	}

	// destructor
	~DirGraph(){

	}

	// returns true iff graph is empty
	bool empty(void){

	}
	
    	// returns in degree of vertex v
	int inDegree(string v){

	}

	// returns out degree of vertex v
	int outDegree(string v){

	}

	// returns number of edges in graph
	int edgeCount(void){

	}

	// returns weight of edge connecting adjacent vertices u and v
	double adjacent(string u, string v){

	}

	// performs a depth first search of graph starting at vertex v
	void DFS(string v){

	}

	// performs a breadth first search of graph starting at vertex v
	void BFS(string v){

	}
    
	// shows the shortest path (using Dijkstra's algorithm) between vertices u and v
	void shortPath(string u, string v){

	}

	// returns shortest distance between vertices u and v
	double distance(string u, string v){

	}

	// builds driected, weighted graph from data provided in text file
	void buildGraph(void){

	}

	// removes all vertices in graph
	void clearGraph(void){

	}

	// marks all vertices as unvisited
	void reset(void){

	}

	// makes an edge between vertices u and v with weight w
	// if an edge already exists, replace its weight with the new w
	void insert(string u, string v, double w){

	}

private:
	// data members
    
};


#endif /* dirGraph_h */
