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
#include <string>
using namespace std;

#define SIZE 20


class HashEntry {
private:
    string key;
    Vertex v;
    
public:
    HashEntry(string key, Vertex v) {
        key = v.vertexName;
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
    
private:
    HashEntry **table;
    
    
public:
    
    HashTable() {
        table = new HashEntry *[SIZE];
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }
    
    ~HashTable() {
        for (int i = 0; i < SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
    
    int hash_fun(string key) const {
        int hash;
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
        
        while (table[hash] != NULL && table[hash]->getKey() != key){
            hash = (hash + 1) % SIZE;
        }
        
        return table[hash]->getVertex();
        
    }
    
    void put(string key, Vertex value) {
        int hash = hash_fun(key);
        
        while (table[hash] != NULL && table[hash]->getKey() != key) {
            hash = (hash + 1) % SIZE;
        }
        
        if (table[hash] != NULL) {
            while (table[hash] != nullptr) {
                hash = (hash + 1) % SIZE;
            }
        }
        table[hash] = new HashEntry(key, value);
    }
    
};


#endif /* HashTable_h */
