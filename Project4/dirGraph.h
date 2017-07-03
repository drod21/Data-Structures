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


#include "HashTable.h"
#include "vertex.h"
#include "edge.h"


#define DIR_GRAPH_SIZE 20

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
        delete[] map.table;
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
        list<Edge>::iterator it = map.table[i].edgeList.begin();
        
        while (it != map.table[i].edgeList.end()) {
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
        list<Edge>::iterator it = map.table[i].edgeList.begin();
        
        while (it != map.table[i].edgeList.end()) {
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
        double w = 0.0;
        Vertex a(u);
        Vertex b(v);
        Edge e(a, b);
        
        int hash = map.hash_fun(u);
        list<Edge>::iterator it = map.table[hash].edgeList.begin();
        while (it != map.table[hash].edgeList.end()) {
            if (*it == e) {
                w = e.weight;
            }
            it++;
        }
        
        
        return w;
    }
    
    // performs a depth first search of graph starting at vertex v
    void DFS(string v) {
        
    }
    
    // performs a breadth first search of graph starting at vertex v
    void BFS(string v) {
        queue<string> q;
        
        q.push(v);
        
        
    }
    
    // shows the shortest path (using Dijkstra's algorithm) between vertices u and v
    void shortPath(string u, string v) {
        
    }
    
    // returns shortest distance between vertices u and v
    double distance(string u, string v) {
        double dis = 0.0;
        
        return dis;
    }
    // builds directed, weighted graph from data provided in text file
    void buildGraph() {
        
        ifstream infile;
        
        string name; //name of vertex
        string from, to; //for edge
        
        double weight;
        
        array<char, 20> ch;
        ifstream input(fileName);
        
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
            char sing_char;
        while (input.good()) {
            input.get(sing_char);
            if (sing_char != ' ')
                ch[i] = sing_char;
            i++;
        }
        
        numberOfVertices = i;
        /*
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
        for (int i = 0; i < DIR_GRAPH_SIZE; i++)
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
        }*/
        //close input file
        infile.close();
        }
        
    }
    
    // removes all vertices in graph
    void clearGraph(void) {
        
    }
    
    // marks all vertices as unvisited
    void reset(void) {
        for (int i = 0; i < DIR_GRAPH_SIZE; i++) {
            if (map.table[i].dataHere) {
                map.table[i].getVertex().uncolor();
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
        
        /*e.setWeight(w);
         vector<list<Edge>>::iterator beg;
         beg = adjList.begin();
         
         list<Edge>::iterator it = adjList[hash].begin(), end;
         for (int i = hash; i < adjList.size(); i = ((i + 1) % DIR_GRAPH_SIZE)) {
         while (it != adjList[i].end()) {
         if (it->getSource() == e.getSource() && it->getTarget() == e.getTarget()) {
         it->setWeight(w);
         } else {
         it->setSource(e.getSource());
         it->setTarget(e.getTarget());
         it->setWeight(e.getWeight());
         }
         it++;
         }
         }
         
         if (table[hash] != NULL) {
         while (table[hash] != nullptr) {
         hash = (hash + 1) % SIZE;
         }
         }
         
         adjList[hash].push_back(e);
         */
        
        /*if (w < 0 || w == 1) {
         throw invalid_argument("invalid arg");
         }
         Vertex *pu;
         *pu = map.get(u);
         Vertex *pv;
         *pv = map.get(v);
         
         //If the vertices do not exist or are equal, throw an illegal
         //argument exception.
         if (pv == NULL || pu == NULL || pv == pu) {
         throw invalid_argument("invalid arg");
         }
         if (w == 0)//remove edge {
         pu->getEdges().remove(Edge(pu, pv, 0));
         }else{
         //add edge
         pu->getEdges().add(Edge(pu, pv, w));
         }*/
    }
    
};


#endif /* dirGraph_h */
