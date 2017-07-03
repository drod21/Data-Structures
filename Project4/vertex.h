/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 vertex.h
 ************************************************************/
#ifndef vertex_h
#define vertex_h

#include <string>
#include <list>
#include "edge.h"

using namespace std;

class Vertex {
    
public:
    // data members
    string vertexName;
    bool colored;
    
    list<Edge> *adjList;
    
    
    Edge e;
    Vertex() : vertexName(""), colored(false), e() {
        
        
    }
    // mutators
    
    void setEdge(Vertex u, Vertex v, double w) {
        e.setSource(u.getVertexName());
        e.setTarget(v.getVertexName());
        e.setWeight(w);
        adjList->push_back(e);
    }
    
    
    
    void setVertexName(string n){
        vertexName = n;
    }
    void color(void){
        colored = true;
    }
    void uncolor(void){
        colored = false;
    }
    
    // accessors
    
    string getVertexName(void){
        return vertexName;
    }
    list<Edge> *getAdj() {
        return adjList;
    }
    
    Edge getEdge() {
        return e;
    }
    bool hasEdge() {
        return (!e.getTarget().empty() && !e.getSource().empty());
    }
    bool isColored(void){
        if(colored == true) return true;
        else return false;
    }
};

#endif /* vertex_h */
