/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 edge.h
 ************************************************************/

#ifndef edge_h
#define edge_h


#include <string>
#include "vertex.h"

using namespace std;

class Edge {
    
private:
    // Maybe we can use Vertex members instead of string?
    Vertex sourceVertex;
    Vertex targetVertex;
    double weight;
public:
    
    Edge() {
        weight = 0.0;
    }
    
    Edge(Vertex s, Vertex t) {
        sourceVertex = s;
        targetVertex = t;
    }
    
    // mutators
    void setWeight(double w) {
        weight = w;
    }
    
    void setSource(Vertex v) {
        sourceVertex = v;
    }
    
    void setTarget(Vertex v) {
        targetVertex = v;
    }
    
    
    // accessors
    double getWeight(void) {
        return weight;
    }
    
    Vertex getSource(void) {
        return sourceVertex;
    }
    
    Vertex getTarget(void) {
        return targetVertex;
    }
    
};

#endif /* edge_h */
