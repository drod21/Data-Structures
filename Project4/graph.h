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

#include "HashTable.h"
#include "vertex.h"
#include "edge.h"

#define MAX_GRAPH_SIZE 20

class Graph {
    
private:
    // we can use either one... I'm honestly unsure of the best way to do it.
    // Check HashTable.h for more
    //HashTable map();
    HashEntry **table;
    Vertex v;
    Edge e;
    
public:
    
    // constructor
    Graph() {
        table = new HashEntry *[MAX_GRAPH_SIZE];
        for (int i = 0; i < MAX_GRAPH_SIZE; i++) {
            table[i] = NULL;
        }
        Vertex u, v;
        Edge e;
        
        u.setVertexName("");
        v.setVertexName("");
        e.setSource(u.getVertexName());
        e.setTarget(v.getVertexName());
    }
    
    // destructor
    ~Graph() {
        
    }
    
    // returns true iff graph is empty
    bool empty(void) {
        bool isEmpty = false;
        
        return isEmpty;
        
    }
    
    // returns degree of vertex v
    int degree(string v) {
        int deg = 0;
        
        return deg;
    }
    
    // returns number of edges in graph
    int edgeCount(void) {
        
        int count = 0;
        
        
        return count;
    }
    
    // returns true if graph is connected
    bool isConnected(string u, string v) {
        bool connected = false;
        
        
        return connected;
    }
    
    // returns weight of edge connecting vertices u and v
    double adjacent(string u, string v) {
        double w = 0.0;
        
        return w;
    }
    
    // performs depth first search of graph starting at vertex v
    void DFS(string v) {
        
    }
    
    // performs breadth first search of graph starting at vertex v
    void BFS(string v) {
        
    }
    
    // uses Prim's algorithm to show minimum spanning tree of
    // the vertices that are connected to v
    void MST(string v) {
        
    }
    
    // builds undirected, weighted graph from data provided in text file
    void buildGraph() {
        
    }
    
    // removes all vertices from graph
    void clear(void) {
        
    }
    
    // marks all vertices as unvisited
    void clearGraph(void) {
        
    }
    
    // inserts an edge with weight w between vertices u and v
    // if edge already exists, update weight with new w
    void insert(string u, string v, double w) {
        
    }
    
    
};

#endif /* graph_h */
