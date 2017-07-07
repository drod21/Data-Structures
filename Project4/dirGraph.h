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
			for(it = map.table[hash]->edgeList.begin();
				it != map.table[hash]->edgeList.end();
				it++){
				if(it->targetVertex == b) return it->weight;
			}
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
        /*
         Vertex currentVertex;
         currentVertex = map.get(v);
         currentVertex.color();
         cout << currentVertex.vertexName << " ";
         int hash = map.hash_fun(v);
         list<Edge>::iterator it;
         for (it = map.table[hash]->edgeList.begin(); it != map.table[hash]->edgeList.end(); ++it) {
         if (!it->targetVertex.colored && it->targetVertex.vertexName != currentVertex.vertexName) {
         it->targetVertex.colored = true;
         DFS(it->targetVertex.vertexName);		// recursive call to DFS
         }
         }
         */
        
        /*Vertex currentVertex;
         currentVertex = map.get(v);
         cout << currentVertex.vertexName << " ";
         currentVertex.color();
         
         int hash = map.hash_fun(v);
         string name;
         Vertex nextVertex;
         if (!map.table[hash]->edgeList.begin()->targetVertex.isColored()) {
         name = map.table[hash]->edgeList.begin()->targetVertex.getVertexName();
         nextVertex = map.get(name);
         }
         
         list<Edge>::iterator it = map.table[hash]->edgeList.begin();
         
         for (it = map.table[hash]->edgeList.begin();
         it != map.table[hash]->edgeList.end();
         ++it) {
         if ((it->targetVertex.vertexName < nextVertex.vertexName)
         && (it->targetVertex.colored == false)) {
         name = it->targetVertex.getVertexName();
         DFS(name);		// recursive call to DFS
         }
         }*/
    }
    
    // performs a breadth first search of graph starting at vertex v
    void BFS(string v) {
        
        bool *visited = new bool[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++) {
            visited[i] = false;
        }
        
        // Queue for BFS traversal
        queue<Vertex> queue;
        // get the first vertex, mark it colored
        Vertex a = map.get(v);
        // temp string
        string s;
        //iterator
        list<Edge>::iterator it;
        // location of v in the table
        int i = map.hash_fun(v);
        
        queue.push(a);
        string temp;
        
        // while the queue is not empty
        while (!queue.empty()) {
            // set s to the vertex at the front of the queue
            //print, then pop.
            s = queue.front().vertexName;
            visited[i] = true;
            cout << s << " ";
            queue.pop();
            int j;
            
            // loop through the table's adjacency list, if the target
            // vertex in that edge is not colored, add it to the queue
            for (it = map.table[i]->edgeList.begin();
                 it != map.table[i]->edgeList.end();
                 ++it) {
                j = map.hash_fun(it->targetVertex.getVertexName());
                if (!visited[j]) {
                    visited[j] = true;
                    queue.push(it->targetVertex);
                }
            }
        }
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
        if (p.vertexName.empty()|| q.vertexName.empty() || p.vertexName == q.vertexName) {
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
        while (it != map.table[hash]->edgeList.end() && it2 != map.table[hash2]->edgeList.end()) {
            if (*it == e) {
                it->weight = e.weight;
            }
            
            if (*it2 == e) {
                it2->weight = e.weight;
            }
            ++it;
            ++it2;
        }
        // insert the edge at both locations, u and v
        map.putEdge(u, e);
        //map.putEdge(v, e);
        
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
