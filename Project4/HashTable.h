//
//  HashTable.h
//  Proj4
//
//  Created by Derek Rodriguez on 6/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h
#include "vertex.h"
#include "edge.h"
#include <string>
using namespace std;

#define SIZE 20


class HashEntry {
    
public:
    
    bool dataHere;
    string key;
    Vertex v;
    list<Edge> edgeList;
    
    HashEntry() : dataHere(false), key("") {
        
    }
    
    HashEntry(string key, Vertex v) {
        key = v.vertexName;
        this->v = v;
    }
    HashEntry(string key, Vertex v, bool here) {
        this->dataHere = here;
        key = v.vertexName;
        this->v = v;
        dataHere = here;
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
    
    HashEntry *table;
    Edge e;
    
    
    HashTable() {
        table = new HashEntry[SIZE];
        for (int i = 0; i < SIZE; i++) {
            table[i].dataHere = false;
        }
    }
    
    ~HashTable() {
        delete[] table;
    }
    
    int hash_fun(string key) const {
        int hash;
        // Generalized string hash function
        // if length > 1, take first and last letter of the string
        // if not, take the character at 0th position
        
        if (key.length() > 1) {
            string::iterator it, it2;
            it = key.begin();
            it = key.end();
            hash = (*it + *it2) % SIZE;
        } else {
            char ch = key.at(0);
            hash = ch % SIZE;
        }
        
        return hash;
    }
    
    Vertex get(string key) {
        int hash = hash_fun(key);
        
        while (table[hash].dataHere && table[hash].getKey() != key){
            hash = (hash + 1) % SIZE;
        }
        // Return the vertex associated with the key
        return table[hash].getVertex();
        
    }
    
    void put(string key, Vertex value) {
        int hash = hash_fun(key);
        
        while (table[hash].dataHere && table[hash].getKey() != key) {
            hash = (hash + 1) % SIZE;
        }
        
        if (table[hash].dataHere) {
            while (table[hash].dataHere) {
                hash = (hash + 1) % SIZE;
            }
        }
        // create new HashEntry and add it to the table
        HashEntry newEntry(key, value, true);
        table[hash] = newEntry;
        
    }
    
    void putEdge(string key, Edge e) {
        int hash = hash_fun(key);
        
        while (table[hash].dataHere && table[hash].getKey() != key){
            hash = (hash + 1) % SIZE;
        }
        // Push the edge to the edge list at the hash position
        table[hash].edgeList.push_back(e);
        
    }

};


#endif /* HashTable_h */
