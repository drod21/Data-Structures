/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 vertex.h
 ************************************************************/
#ifndef vertex_h
#define vertex_h

#include <string>

using namespace std;

class Vertex {
    
public:
	// mutators
	void setVertexName(string n){
		vertexName = n;
	}

	
	// accessors
	string getVertexName(void){
		return vertexName;
	}
    
    
private:
    	// data members
    	string vertexName;
};

#endif /* vertex_h */
