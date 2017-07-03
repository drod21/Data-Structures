/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 vertex.h
 ************************************************************/
#ifndef vertex_h
#define vertex_h

#include <string>
#include <list>

using namespace std;

class Vertex {
    
public:
    // data members
    string vertexName;
    bool colored;
    
    Vertex() : vertexName(""), colored(false) {
        
        
    }
    // mutators
    
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
    
    bool isColored(void){
        if(colored == true) return true;
        else return false;
    }
};

#endif /* vertex_h */
