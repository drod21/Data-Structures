/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 dirGraph.h
 ************************************************************/

#ifndef dirGraph_h
#define dirGraph_h
// includes. total includes may get cut down, but lets bring in stack and queue for now
#include <list>
#include <fstream>
#include <queue>
#include <stack>
#include "HashTable.h"
#include "vertex.h"
#include "edge.h"


#define DIR_GRAPH_SIZE 20

class DirGraph {
    
private:
    //HashTable map();
    HashEntry **table;
    Vertex u, v;
    Edge e;
    
public:
    
    DirGraph() {
        table = new HashEntry *[DIR_GRAPH_SIZE];
        for (int i = 0; i < DIR_GRAPH_SIZE; i++) {
            table[i] = NULL;
        }
        
        u.setVertexName("");
        v.setVertexName("");
        e.setSource(u.getVertexName());
        e.setTarget(v.getVertexName());
    }
    
    // destructor
    ~DirGraph(){
        
    }
    
    // returns true iff graph is empty
    bool empty(void) {
        bool isEmpty = false;
        
        return isEmpty;
    }
    
    // returns in degree of vertex v
    int inDegree(string v) {
        int deg = 0;
        
        return deg;
    }
    
    // returns out degree of vertex v
    int outDegree(string v) {
        int deg = 0;
        
        return deg;
    }
    
    // returns number of edges in graph
    int edgeCount(void) {
        
        int count = 0;
        
        
        return count;
    }
    
    // returns weight of edge connecting adjacent vertices u and v
    double adjacent(string u, string v) {
        double w = 0.0;
        
        return w;
    }
    
    // performs a depth first search of graph starting at vertex v
    void DFS(string v) {
        
    }
    
    // performs a breadth first search of graph starting at vertex v
    void BFS(string v) {
        
    }
    
    // shows the shortest path (using Dijkstra's algorithm) between vertices u and v
    void shortPath(string u, string v) {
        
    }
    
    // returns shortest distance between vertices u and v
    double distance(string u, string v) {
        double dis = 0.0;
        
        return dis;
    }
    
    // builds driected, weighted graph from data provided in text file
    void buildGraph(void) {
        
    }
    
    // removes all vertices in graph
    void clearGraph(void) {
        
    }
    
    // marks all vertices as unvisited
    void reset(void) {
        
    }
    
    // makes an edge between vertices u and v with weight w
    // if an edge already exists, replace its weight with the new w
    void insert(string u, string v, double w) {
        
    }
    
};


#endif /* dirGraph_h */
