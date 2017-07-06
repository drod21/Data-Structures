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
            if (it->sourceVertex == a && it->targetVertex == b) {
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


		// reset graph before beginning function
		Vertex currentVertex;
        stack<string> s;
        
        int hash = map.hash_fun(v);
        s.push(v);
		currentVertex = map.get(v);
        
        list<Edge>::iterator it = map.table[hash]->edgeList.begin();
        while (!s.empty()) {
            string print = s.top();
            if (!it->targetVertex.colored) {
                cout << print << " ";
                currentVertex.color();
            }
            s.pop();
		for (it = map.table[hash]->edgeList.begin(); it != map.table[hash]->edgeList.end(); ++it){
			if (!it->targetVertex.colored && it->targetVertex.vertexName != currentVertex.vertexName) {
                it->targetVertex.colored = true;
                s.push(it->targetVertex.vertexName);
                //DFS(it->targetVertex.vertexName);		// recursive call to DFS
			}
		}
        }
    }
    
    // performs breadth first search of graph starting at vertex v
    // non-recursive
    void BFS(string v) {
        // Queue for BFS traversal
        queue<Vertex> q;
        // get the first vertex, mark it colored
        Vertex a = map.get(v);
        a.colored = true;
        q.push(a);
        // temp string
        string s;
        //iterator
        list<Edge>::iterator it;
        // location of v in the table
        int i = map.hash_fun(v);
        
        // while the queue is not empty
        while (!q.empty()) {
            // set s to the vertex at the front of the queue
            //print, then pop.
            s = q.front().vertexName;
            cout << s << " ";
            q.pop();
            
            // loop through the table's adjacency list, if the target
            // vertex in that edge is not colored, add it to the queue
            for (it = map.table[i]->edgeList.begin(); it != map.table[i]->edgeList.end(); ++it) {
                if (!it->targetVertex.colored && it->targetVertex.vertexName != v) {
                    it->targetVertex.colored = true;
                    q.push(it->targetVertex);
                }
            }
        }
    }

    
    // uses Prim's algorithm to show minimum spanning tree of
    // the vertices that are connected to v
    void MST(string v) {
        
    }
    
    // builds undirected, weighted graph from data provided in text file
    void buildGraph() {
        ifstream infile;
        
        string line;
        string name; //name of vertex
        string from, to; //for edge
        
        double w;
        
        array<char, 20> ch;
        vector<Vertex> mVertex;
        
        //open file for reading
        infile.open(fileName);
        
        //check input file
        if(infile.fail()) {
            cerr << "Could not open the file " << fileName << endl;
            return;
        } else {
            int i = 0;
            // read the first line, count for number of vertices
            
            getline(infile, line);
            int j;
            for (i = 0, j = 0; i < line.length(); i++) {
                if (isalpha(line[i])) {
                    numberOfVertices++;
                    ch[j++] = line[i];
                }
            }
            
            // put the vertex names in the vertex vector, then in hash map.
            for (i = 0; i < numberOfVertices; i++) {
                name = ch[i];
                p.vertexName = name;
                mVertex.push_back(p);
            }
            
            for (Vertex vert : mVertex) {
                map.put(vert.vertexName, vert);
            }
            while (!infile.eof()) {
                infile >> from;
                infile >> to;
                infile >> w;
                numberOfEdges++;
                try {
                    insert(from, to, w);
                } catch(invalid_argument &e) {
                    cout << e.what() << endl;
                }
            }
        }
        //close input file
        infile.close();
        
    }
    
    // removes all vertices from graph
    void clear(void) {
      
    }
    
    // marks all vertices as unvisited
    void reset(void) {
        for (int i = 0; i < MAX_GRAPH_SIZE; i++) {
            if (map.table[i] != nullptr) {
                map.table[i]->getVertex().uncolor();
            }
        }  
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
        int hash = map.hash_fun(u);
        list<Edge>::iterator it = map.table[hash]->edgeList.begin();
        while (it != map.table[hash]->edgeList.end()) {
            if (it->targetVertex == e.sourceVertex || it->sourceVertex == e.targetVertex) {
                it->weight = e.weight;
            }
            
            if (it->sourceVertex == e.sourceVertex || it->targetVertex == e.targetVertex) {
                it->weight = e.weight;
            }
            ++it;
        }

        // insert the edge at both locations, u and v
        map.putEdge(u, e);
        map.putEdge(v, e);
    }
    
    
};

#endif /* graph_h */
