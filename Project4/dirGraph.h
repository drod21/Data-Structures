/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 dirGraph.h
 ************************************************************/

#ifndef dirGraph_h
#define dirGraph_h
#include <list>
#include <fstream>
#include <array>
#include <queue>
#include <stack>
#include <limits>
#include <cstdlib>


#include "HashTable.h"
#include "vertex.h"
#include "edge.h"


#define DIR_GRAPH_SIZE 20
#define INFINITY 1000 		// for use with Dijkstra's algorithm

class DirGraph {
    
private:
    HashTable map;
    vector<Vertex *> vertList;
    Vertex p;
    string fileName;
    int numberOfVertices; //number of vertices
    int numberOfEdges; //number of edges
    
public:
    
    DirGraph() {
        for (Vertex *v : vertList) {
            v = nullptr;
        }
        numberOfVertices = 0;
        numberOfEdges = 0;
    }
    
    DirGraph(string file_name) {
        for (Vertex *v : vertList) {
            v = nullptr;
        }
        numberOfVertices = 0;
        numberOfEdges = 0;
        fileName = file_name;
        buildGraph();
    }
    
    // destructor
    ~DirGraph() {
        //delete[] map.table;
        numberOfEdges = 0;
        numberOfVertices = 0;
        fileName = "";
    }
    
    // returns true iff graph is empty
    bool empty(void) {
        /*bool notEmpty = false;
         for (int i = 0; i < DIR_GRAPH_SIZE; i++) {
         if (map.table[i].dataHere)
         notEmpty = true;
         }
         
         return notEmpty;*/
        
        if (numberOfVertices > 0) {
            return false;
        }
        return true;
    }
    
    // returns in degree of vertex v
    // Need to loop through whole array
    int inDegree(string v) {
        int deg = 0;
        /*Vertex a = map.get(v);
         
         list<Edge>::iterator it;
         for (int i = 0; i < DIR_GRAPH_SIZE; i++) {
         it = map.table[i].edgeList.begin();
         while (it != map.table[i].edgeList.end()) {
         if (it->getTarget().vertexName == a.vertexName) {
         deg++;
         }
         }
         }
         */
        int i = map.hash_fun(v);
        list<Edge>::iterator it = map.table[i]->edgeList.begin();
        
        while (it != map.table[i]->edgeList.end()) {
            if (it->targetVertex.vertexName == v) {
                deg++;
            }
            it++;
        }
        
        return deg;
    }
    
    // returns out degree of vertex v
    int outDegree(string v) {
        int deg = 0;
        
        int i = map.hash_fun(v);
        list<Edge>::iterator it = map.table[i]->edgeList.begin();
        
        while (it != map.table[i]->edgeList.end()) {
            if (it->sourceVertex.vertexName == v) {
                deg++;
            }
            it++;
        }
        
        return deg;
    }
    
    // returns number of edges in graph
    int edgeCount(void) {
        return numberOfEdges;
    }
    
    // returns weight of edge connecting adjacent vertices u and v
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
            if(it->sourceVertex == a && it->targetVertex == b){
                w = adjacentAux(a, b);
            }
            it++;
        }
        return w;
    }
    
    double adjacentAux(Vertex a, Vertex b){
        int hash = map.hash_fun(a.vertexName);
        list<Edge>::iterator it;
        for (it = map.table[hash]->edgeList.begin();
             it != map.table[hash]->edgeList.end();
             it++) {
            if(it->targetVertex == b) return it->weight;
        }
        return -1;
    }
    
    void DFS_Aux(string v, bool visited[]) {
        // use separate array to mark each visited or not
        int hash = map.hash_fun(v);
        visited[hash] = true;
        cout << v << " ";
        int j;
        
        list<Edge>::iterator i;
        for (i = map.table[hash]->edgeList.begin();
             i != map.table[hash]->edgeList.end();
             ++i) {
            j = map.hash_fun(i->targetVertex.getVertexName());
            if (!visited[j]) {
                DFS_Aux(i->targetVertex.getVertexName(), visited);
            }
        }
    }
    
    // performs a depth first search of graph starting at vertex v
    void DFS(string v) {
        
        bool *visited = new bool[numberOfVertices];
        
        for (int i = 0; i < numberOfVertices; i++) {
            visited[i] = false;
        }
        
        DFS_Aux(v, visited);
        
        delete [] visited;
    }
    
    // Auxiliary function for BFS
    void BFS_Aux(string v, bool visited[], queue<Vertex> q) {
        // loop through and set vertex from initial vertex's list, then use the new
        // vertex's edge list to do the same, etc.
        //iterator
        list<Edge>::iterator it;
        string temp;
        string s;
        // while the queue is not empty
        while (!q.empty()) {
            // set s to the vertex at the front of the queue
            //print, then pop.
            s = q.front().vertexName;
            cout << s << " ";
            q.pop();
            int j;
            
            int i = map.hash_fun(v);
            // loop through the table's adjacency list, if the target
            // vertex in that edge is not colored, add it to the queue
            for (it = map.table[i]->edgeList.begin();
                 it != map.table[i]->edgeList.end();
                 ++it) {
                string temp;
                temp = it->targetVertex.vertexName;
                j = map.hash_fun(temp);
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(it->targetVertex);
                }
            }
        }
    }
    
    // performs a breadth first search of graph starting at vertex v
    void BFS(string v) {
        
        bool *visited = new bool[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++) {
            visited[i] = false;
        }
        // get the first vertex, mark it colored
        Vertex a = map.get(v);
        // location of v in the table
        int i = map.hash_fun(v);
        visited[i] = true;
        
        queue<Vertex> q;
        q.push(a);
        
        BFS_Aux(v, visited, q);
        
        delete [] visited;
        
    }
    
    // shows the shortest path (using Dijkstra's algorithm) between vertices u and v
    void shortPath(string u, string v) {
        double cost[DIR_GRAPH_SIZE][DIR_GRAPH_SIZE];	// cost table for total weight
        array<double, DIR_GRAPH_SIZE> D;				// distance table
        array<string, DIR_GRAPH_SIZE> P;				// predecessor table;
        // start and end for use with cost, distance, and predecessor tables
        int start = map.hash_fun(u);
        int end = map.hash_fun(v);
        /*
         int start = stoi(u) - 65;		// 65 is ASCII A value
         int end = stoi(v) - 65;
         */
        
        // populate cost table with weights of edges connecting vertices
        // diagonal of cost table becomes 0's
        for(int i = 0; i < DIR_GRAPH_SIZE; i++){
            for(int j = 0; j < DIR_GRAPH_SIZE; j++){
                if(adjacent(u, v) == -1) cost[i][j] = INFINITY;
                else cost[i][j] = adjacent(u, v);
            }
        }
        /*
         // set diagonal of cost table (distance of any vertex to itself) to 0
         for(int i = 0; i < DIR_GRAPH_SIZE; i++){
         cost[i][i] = 0;
         }
         */
        
        // populate distance table with inital distances
        // populate predecessor table with nil
        for(int i = 0; i < DIR_GRAPH_SIZE; i++){
            D[i] = cost[start][i];
            P[i] = "nil";
        }
    }
    
    // returns shortest distance between vertices u and v
    double distance(string u, string v) {
        double dis = 0.0;
        
        return dis;
    }
    // builds directed, weighted graph from data provided in text file
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
    
    // removes all vertices in graph
    void clearGraph(void) {
        
    }
    
    // marks all vertices as unvisited
    void reset(void) {
        list<Edge>::iterator it;
        for (int i = 0; i < DIR_GRAPH_SIZE; i++) {
            if (map.table[i] != nullptr) {
                it = map.table[i]->edgeList.begin();
                it->sourceVertex.colored = false;
                it->targetVertex.colored = false;
                map.table[i]->getVertex().uncolor();
            }
        }
    }
    
    // makes an edge between vertices u and v with weight w
    // if an edge already exists, replace its weight with the new w
    void insert(string u, string v, double w) {
        if (w <= 0) {
            throw invalid_argument("invalid arg");
        }
        
        
        
        Vertex p = map.get(u);
        Vertex q = map.get(v);
        
        //If the vertices do not exist or are equal, throw an illegal
        //argument exception.
        if ((p.vertexName.empty()) || (q.vertexName.empty())
            || (p.vertexName == q.vertexName)) {
            throw invalid_argument("invalid arg");
        }
        
        Vertex m;
        m.setVertexName(u);
        Vertex n;
        n.setVertexName(v);
        
        Edge e(m, n, w);
        int hash = map.hash_fun(u);
        int hash2 = map.hash_fun(v);
        list<Edge>::iterator it = map.table[hash]->edgeList.begin();
        list<Edge>::iterator it2 = map.table[hash2]->edgeList.begin();
        if ((adjacent(u,v) != -1)) {
            while (it != map.table[hash]->edgeList.end() &&
                   it2 != map.table[hash2]->edgeList.end()) {
                if (*it == e) {
                    it->weight = e.weight;
                }
                
                if (*it2 == e) {
                    it2->weight = e.weight;
                }
                ++it;
                ++it2;
            }
        } else {
            // insert the edge at both locations, u and v
            map.putEdge(u, e);
            numberOfEdges++;
            
        }
    }
    
};


#endif /* dirGraph_h */
