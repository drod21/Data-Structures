/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 edge.h
 ************************************************************/

#ifndef edge_h
#define edge_h

#include <string>

using namespace std;

class Edge {
    
public:
	// mutators
    	void setWeight(double w){
		weight = w;
	}

	void setSource(string v){
		sourceVertex = v;
	}
	
	void setTarget(string v){
		targetVertex = v;
	}


	// accessors
	double getWeight(void){
		return weight;
	}

	string getSource(void){
		return sourceVertex;
	}

	string getTarget(void){
		return targetVertex;
	}
    
private:
	// data members
    	double weight;
	string sourceVertex;
	string targetVertex;
    
    
    
};

#endif /* edge_h */
