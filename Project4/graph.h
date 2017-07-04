/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 graph.h
 ************************************************************/

#ifndef graph_h
#define graph_h

#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <array>

#include "HashTable.h"
#include "vertex.h"
#include "edge.h"

#define MAX_GRAPH_SIZE 20

// adjacency list structure
/*
struct adjacencyList{
    string vertexName;
    string* next;
};
*/

class Graph {
    
private:
	/*
    HashEntry **table;
    Vertex v;
    Edge e;
    vector<adjacencyList*> adjListVector;
    */

    HashTable map;
    vector<Vertex *> vertList;
    Vertex p;
    string fileName;
    int numberOfVertices; //number of vertices
    int numberOfEdges; //number of edges

public:
    
    // constructor
    Graph() {
		/*
        table = new HashEntry *[MAX_GRAPH_SIZE];
        for (int i = 0; i < MAX_GRAPH_SIZE; i++) {
            table[i] = NULL;
        }
        Vertex u, v;
        Edge e;
        
        u.vertexName = "";
        v.vertexName = "";
        e.setSource(u);
        e.setTarget(v);
		*/

        for (Vertex *v : vertList) {
            v = nullptr;
        }
        numberOfVertices = 0;
        numberOfEdges = 0;
    }
	// constructor
    Graph(string file_name) {
        for (Vertex *v : vertList) {
            v = nullptr;
        }
        numberOfVertices = 0;
        numberOfEdges = 0;
        fileName = file_name;
        buildGraph();
    }
    
    // destructor
    ~Graph() {
        
    }
    
    // returns true iff graph is empty
    bool empty(void) {
		if(numberOfVertices == 0) return true;
		else return false;
    }
    
    // returns degree of vertex v
    int degree(string v) {
        int deg = 0;
		int i = map.hash_fun(v);
	    list<Edge>::iterator it = map.table[i]->edgeList.begin(); 
        while (it != map.table[i]->edgeList.end()) {
			deg++;
            it++;
        }
        return deg;
    }
    
    // returns number of edges in graph
    int edgeCount(void) {
        return numberOfEdges;
    }
    
    // returns true if graph is connected
    bool isConnected(string u, string v) {
        bool connected = false;
        
        
        return connected;
    }
    
    // returns weight of edge connecting vertices u and v
    double adjacent(string u, string v) {
		// will return -1 (infinity) if vertices do not share an edge
        double w = -1;
        // if same vertex, return 0
        if(u == v){
			w = 0.0;
			return w;
		}
        Vertex a(u);
        Vertex b(v);
        Edge e(a, b);       
        int hash = map.hash_fun(u);
        list<Edge>::iterator it = map.table[hash]->edgeList.begin();
        while (it != map.table[hash]->edgeList.end()) {
            if (*it == e) {
                w = e.weight;
            }
            it++;
        }
        return w;
    }
    
    // performs depth first search of graph starting at vertex v
    // recursive
    void DFS(string v) {
        /* PSEUDO-CODE
         reset graph so all vertices are uncolored
         label v as visited
         for all edges in v
         if edge is unvisited
         temp = vertex on other side of edge
         if temp is uncolored
         label edge as discovery edge
         print vertex
         recursively call DFS(temp)
         else label edge as back edge
         */
    }
    
    // performs breadth first search of graph starting at vertex v
    // non-recursive
    void BFS(string v) {
        /*
        	initialize collectionn L0 to contain vertex v
         int i = 0
         for all vertices in Li
         for all edges on vertex
         if edge is unexplored
         tempVertex = vertex on opposite side of edge
         if tempVertex is unexplored
         label edge as discovery edge
         insert tempVertex into Li+1
         else label edge as cross edge
         print tempVertex
         i++
         */
    }
    
    // uses Prim's algorithm to show minimum spanning tree of
    // the vertices that are connected to v
    void MST(string v) {
        
    }
    
    // builds undirected, weighted graph from data provided in text file
    void buildGraph() {
		ifstream infile;
		// open file for reading
		infile.open(fileName, ios::in);
		if(!infile){
			cerr << "Error. file could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		string from, to, temp;
		double weight;

		// DEBUGGING: output contetns of file
		getline(infile, temp);
		cout << "contents of file: " << endl;
		cout << temp << endl;
		while(infile >> from >> to >> weight){
			cout << from << " " << to << " " << weight << endl;
		}
		cout << endl;
		infile.clear();
		infile.seekg(0, ios::beg);
		// END DEBUGGING

		// use first line of file to get number of vertices
		getline(infile, temp);
		for(int i = 0; i < temp.length(); i++){
			if(isalpha(temp[i])) numberOfVertices++;
		}
		cout << "number of vertices: " << numberOfVertices << endl;	// DEBUGGING

		// use remaining lines to 

        
    }
    
    // removes all vertices from graph
    void clear(void) {
        
    }
    
    // marks all vertices as unvisited
    void reset(void) {
        /* PSEUDO-CODE
         for each vertex in adjListVector
         uncolor vertex
         while currentVertex->next != null
         currentVertex = currentVertex->next
         uncolor vertex
         print graph colring reset
         */
    }
    
    // inserts an edge with weight w between vertices u and v
    // if edge already exists, update weight with new w
    void insert(string u, string v, double w) {
        if (w <= 0) {
            throw invalid_argument("invalid arg");
        }
        
        Vertex p = map.get(u);
        Vertex q = map.get(v);
        
        //If the vertices do not exist or are equal, throw an illegal
        //argument exception.
        if (p.vertexName.empty()|| q.vertexName.empty() || p.vertexName == q.vertexName) {
            throw invalid_argument("invalid arg");
        }
        
        Vertex m;
        m.setVertexName(u);
        Vertex n;
        n.setVertexName(v);
        
        Edge e(m, n, w);
        
        // insert the edge at both locations, u and v
        map.putEdge(u, e);
        map.putEdge(v, e);
    }
    
    
};

#endif /* graph_h */
