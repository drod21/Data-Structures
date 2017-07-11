/************************************************************
 Derek Rodriguez, Derek Caprio
 COP 4530 Project 4
 HashTable.h
 ************************************************************/
#ifndef HashTable_h
#define HashTable_h
#include "vertex.h"
#include "edge.h"
#include <string>
using namespace std;

#define SIZE 20


class HashEntry {

public:
    string key;
    Vertex v;
    list<Edge> edgeList;
    
    HashEntry() {       
    }
    
    HashEntry(string key, Vertex v) {
        //key = v.vertexName;
		this->key = key;
        this->v = v;
    }
    
    string getKey() {
        return key;
    }

    Vertex getVertex() {
        return v;
    }
};

class HashTable {
    
public:
    
    HashEntry *table[SIZE];
    Edge e;
   
    HashTable() {     
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }
    
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            if (table[i] != nullptr)
                delete table[i];
        }
    }
    
    int hash_fun(string key) const {
        int hash;
        char ch = key[0];
        hash = ch % SIZE;        
        return hash;
    }
    
    Vertex get(string key) {
        int hash = hash_fun(key);        
        while (table[hash] != nullptr && table[hash]->getKey() != key){
            hash = (hash + 1) % SIZE;
        }
        bool found = false;
        // Return the vertex associated with the key
        if (key != table[hash]->v.vertexName) {
            while (table[hash] != nullptr && table[hash]->v.vertexName != key){
                hash = (hash + 1) % SIZE;
            }
        } else {
            found = true;
        }
        
        if (!found) {
            throw invalid_argument("invalid arg");
        }
        
        return table[hash]->v;
    }
    
    void put(string key, Vertex value) {
        int hash = hash_fun(key);       
        while (table[hash] != nullptr  && table[hash]->getKey() != key) {
            hash = (hash + 1) % SIZE;
        }
        
        if (table[hash] != nullptr) {
            while (table[hash] != nullptr) {
                hash = (hash + 1) % SIZE;
            }
        }
        // create new HashEntry and add it to the table
        //HashEntry hashEnt(key, value);
        
        table[hash] = new HashEntry(key, value);
        
    }
    
    void putEdge(string key, Edge e) {
        int hash = hash_fun(key);
        
        while (table[hash] != nullptr && table[hash]->getKey() != key){
            hash = (hash + 1) % SIZE;
        }
        // Push the edge to the edge list at the hash position
        table[hash]->edgeList.push_back(e);        
    }
};

#endif /* HashTable_h */
