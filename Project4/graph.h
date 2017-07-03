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
#include <array>
#include <fstream>

#include "HashTable.h"
#include "vertex.h"
#include "edge.h"

#define MAX_GRAPH_SIZE 20

// adjacency list structure
struct adjacencyList{
    string vertexName;
    string* next;
};

class Graph {
    
private:
    int numberOfVertices; //number of vertices
    int numberOfEdges = 0; //number of edges
    HashTable map;
    HashEntry **table;
    Vertex v;
	Vertex p;
    Edge e;
    vector<adjacencyList*> adjListVector;
    
public:
    
    // constructor
    Graph() {
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
        /* PSEUDO-CODE
         while adjacency list at vector element v is not null
         deg++
         move to next item in adjacency list
         */
        
        return deg;
    }
    
    // returns number of edges in graph
    int edgeCount(void) {
        return numberOfEdges;
    }
    
    // returns true if graph is connected
    bool isConnected(void) {
        bool connected = false;
        
        
        return connected;
    }
    
    // returns weight of edge connecting vertices u and v
    double adjacent(string u, string v) {
        double w = 0.0;
        // if same vertex, return 0
        if(u == v) return w;
        /* PSEUDO-CODE
         temp = u's position in adjListVector
         while vertex at adjancyList[u]->next != v
         tempVertex = currentVertex->next
         if get to end of adjancyList return -1
         return getEdge between u and currentVertex
         */
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
        
        //data of file
        
        
        string name; //name of vertex
        string from, to; //for edge
        
        double weight;
        
        array<char, 20> ch;
        
        vector<Vertex> mVertex;
        
        string fname = "graph.txt";
        
        //open file for reading
        infile.open(fname);
        
        //check input file
        if(infile.fail()) {
            //cerr << "Could not open the file " << filename here << endl;
            return;
        }
        int i = 0;
        // read the first line, count for number of vertices
        while (infile >> ch[i] && cin.peek() != '\n') {
            i++;
        }
        
        numberOfVertices = i;
        
        // put the vertex names in the vertex vector, then in hash map.
        for (i = 0; i < ch.size(); i++) {
            name = ch[i];
            p.vertexName = name;
            mVertex.push_back(p);
        }
        
        for (Vertex vert : mVertex) {
            map.put(vert.getVertexName(), vert);
        }
        
        
        //read the edges
        for (int i = 0; i < MAX_GRAPH_SIZE; i++)
        {
            infile >> from;
            infile >> to;
            infile >> weight;
            numberOfEdges++;
            try{
                insert(from, to, weight);
            } catch(invalid_argument &e) {
                cout << e.what() << endl;
            }
        }//end  for
        
        //close input file
        infile.close();
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
        Vertex pu = map.get(u);
        Vertex pv = map.get(v);
        
        //If the vertices do not exist or are equal, throw an illegal
        //argument exception.
        if (pv.vertexName.empty()|| pu.vertexName.empty() || pv.vertexName == pu.vertexName) {
            throw invalid_argument("invalid arg");
        }
        
        Vertex m;
        m.setVertexName(u);
        Vertex n;
        n.vertexName = v;
		Edge e;
		e.weight = w;
		e.sourceVertex = pu;
		e.targetVertex = pv;
    }
    
    
};

#endif /* graph_h */
