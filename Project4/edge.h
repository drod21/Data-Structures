/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 edge.h
 ************************************************************/

#ifndef edge_h
#define edge_h

#include "vertex.h"
#include <string>

using namespace std;

class Edge {
    
private:
    // Maybe we can use Vertex members instead of string?
    string sourceVertex;
    string targetVertex;
    double weight;
public:
    
    Edge() {
        weight = 0.0;
    }
    
    Edge(string s, string t) {
        sourceVertex = s;
        targetVertex = t;
    }
    
    // mutators
    void setWeight(double w) {
        weight = w;
    }
    
    void setSource(string v) {
        sourceVertex = v;
    }
    
    void setTarget(string v) {
        targetVertex = v;
    }
    
    
    // accessors
    double getWeight(void) {
        return weight;
    }
    
    string getSource(void) {
        return sourceVertex;
    }
    
    string getTarget(void) {
        return targetVertex;
    }
    
};

#endif /* edge_h */
