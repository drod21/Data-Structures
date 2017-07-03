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
    
public:
    Vertex sourceVertex;
    Vertex targetVertex;
    double weight;
    
    Edge() {
        weight = 0.0;
    }
    
    Edge(Vertex s, Vertex t) {
        sourceVertex = s;
        targetVertex = t;
    }
    
    Edge(Vertex s, Vertex t, double w) {
        sourceVertex = s;
        targetVertex = t;
        weight = w;
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
    
    // overloaded assignment operator
    Edge& operator=(const Edge& original) {
        Edge *m = new Edge;
        
        m->sourceVertex = original.sourceVertex;
        m->targetVertex = original.targetVertex;
        m->weight = original.weight;
        
        return *m;
    }
    // overload equality operator to compare two edges
    bool operator==(const Edge &orig) const {
        return ((sourceVertex == orig.sourceVertex) && (targetVertex == orig.targetVertex));
    }
    
};

#endif /* edge_h */
