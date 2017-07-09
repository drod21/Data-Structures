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
    
    bool isCycle(Vertex a, vector<Vertex> notMst) {
        
        int count = 0;
        
        for (Vertex vert : notMst) {
            
            if (adjacent(vert, a) != -1) {
                count++;
            }
        }
        
        if (count >= 2) {
            return true;
            
        }
        
        return false;
        
    }
    
    // returns weight of edge connecting vertices u and v
    double adjacent(string u, string v) {
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
        list<Edge>::iterator it = map.table[hash]->
        edgeList.begin();
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
            int h = map.hash_fun(i->sourceVertex.getVertexName());
            if (!visited[j]) {
                DFS_Aux(i->targetVertex.getVertexName(), visited);
            }
            if (!visited[h]) {
                DFS_Aux(i->sourceVertex.getVertexName(), visited);
            }
        }
    }
    
    // performs depth first search of graph starting at vertex v
    // recursive
    void DFS(string v) {
        
        bool *visited = new bool[numberOfVertices];
        
        for (int i = 0; i < numberOfVertices; i++) {
            visited[i] = false;
        }
        
        DFS_Aux(v, visited);
        
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
            
            int i = map.hash_fun(s);
            // loop through the table's adjacency list, if the target
            // vertex in that edge is not colored, add it to the queue
            for (it = map.table[i]->edgeList.begin();
                 it != map.table[i]->edgeList.end();
                 ++it) {
                j = map.hash_fun(it->targetVertex.getVertexName());
                int h = map.hash_fun(it->sourceVertex.vertexName);
                
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(it->targetVertex);
                }
                
                
                if (!visited[h]) {
                    visited[h] = true;
                    q.push(it->sourceVertex);
                }
                
            }
        }
        
    }

    
    // uses Prim's algorithm to show minimum spanning tree of
    // the vertices that are connected to v
    void MST(string v) {
	/*
	PSEUDO CODE
	initialize MSTset to empty
	add v to MSTset
	find shorteset edge from v, add its target to MSTset, totalCost = edge legnth
	while MSTset does not include all vertices
		find shortest edge from all vertices in MSTset that does not lead to an already visited vertex and add that target to MSTset, totalCost += edge legnth
	*/
       
	// graph reset in menu program
		// set up notMSTset
		double MSTweight = 0;
		vector<Vertex> MSTset;
		vector<Vertex> notMSTset;
		for(int i = 0; i < MAX_GRAPH_SIZE; i++){
			if(map.table[i] != nullptr){
				notMSTset.push_back(map.table[i]->getVertex());
			}
		}
		// DEBUGGING
		/*
		cout << "notMSTset: ";
		//for(int i = 0; i < numberOfVertices; i++){
		for(Vertex v: notMSTset){
			notMSTset.pop_back();
			cout << v.vertexName << " ";
		}
		cout << endl;
		*/
		// END DEBUGGING
		
		// build MST
		while(!notMSTset.empty()){
			Vertex currentVertex = *(notMSTset.end());
			int hash = map.hash_fun(currentVertex.vertexName);
        	list<Edge>::iterator it;
			Edge shortestEdge = *(map.table[hash]->edgeList.begin());
			for(it = map.table[hash]->edgeList.begin(); 
				it != map.table[hash]->edgeList.end();
				++it){
				if(/*it->weight < shortestEdge.weight &&
				   targetInMST == true &&
				   it is not used edge &&
				   does not form a loop */){
						shortestEdge = *it;
						MSTset.push_back(currentVertex);
						currentVertex.color();
						MSTweight += shortestEdge.weight;
						notMSTset.pop_back();
				}
					
			}
		}

		// display MST and MST weight
		cout << "MST: ";
		for(Vertex v: MSTset){
			cout << v.vertexName << " ";			
		}
		cout << endl << "MST weight: " << MSTweight << endl; 
		

		/*
		Vertex currentVertex = map.get(v);
		// start by adding closest vertex to v to MSTset
		MSTset.push_back(currentVertex);
		currentVertex.color();
		int hash = map.hash_fun(v);
		Edge shortestEdge;
		shortestEdge = *(map.table[hash]->edgeList.begin());
		Vertex nextVertex;
		nextVertex = map.table[hash]->edgeList.begin()->targetVertex;
        list<Edge>::iterator it;
		for(it = map.table[hash]->edgeList.begin(); it != map.table[hash]->edgeList.end(); ++it){
			if((it->weight < shortestEdge.weight) && (it->targetVertex.colored == false)){
				shortestEdge = *it;
			}		
		}
		MSTweight += shortestEdge.weight;
		nextVertex = shortestEdge.targetVertex;
		nextVertex.color();
		MSTset.push_back(nextVertex);

		currentVertex = nextVertex;
		// while MSTset does not consist of all vertices, find shortest weight that
		// does not make a loop and add its target to the MSTset 
		while(MSTset.size() < numberOfVertices){
			for(int i = 0; i < MSTset.size(); i++){
				hash = map.hash_fun(currentVertex.vertexName)
				shortestEdge = *(map.table[hash]->edgeList.begin());
				if(currentVertex.targetVertex )
				
			}
		}
		*/
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
        Edge e2(n, m, w);
        
        int hash = map.hash_fun(u);
        int hash2 = map.hash_fun(v);
        list<Edge>::iterator it = map.table[hash]->edgeList.begin();
        list<Edge>::iterator it2 = map.table[hash2]->edgeList.begin();
        if ((adjacent(u, v) != -1) || (adjacent(v,u) != -1)) {
            while (it != map.table[hash]->edgeList.end()) {
                if (it->targetVertex.vertexName == e.sourceVertex.vertexName || it->sourceVertex.vertexName == e.targetVertex.vertexName) {
                    it->weight = e.weight;
                } else if (it->sourceVertex.vertexName == e.sourceVertex.vertexName|| it->targetVertex.vertexName == e.targetVertex.vertexName) {
                    it->weight = e.weight;
                }
                if (it2->targetVertex.vertexName == e.sourceVertex.vertexName || it2->sourceVertex.vertexName == e.targetVertex.vertexName) {
                    it2->weight = e.weight;
                } else if (it2->sourceVertex.vertexName == e.sourceVertex.vertexName|| it2->targetVertex.vertexName == e.targetVertex.vertexName) {
                    it2->weight = e.weight;
                }
                ++it;
                ++it2;
            }
        } else {
            map.putEdge(u, e);
            map.putEdge(u, e2);
            map.putEdge(v, e);
            map.putEdge(v, e2);
            numberOfEdges++;
        }

        // insert the edge at both locations, u and v
    }
    
    
};

#endif /* graph_h */
