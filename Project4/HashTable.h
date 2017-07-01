//
//  HashTable.h
//  Proj4
//
//  Created by Derek Rodriguez on 6/30/17.
//  Copyright © 2017 Derek Rodriguez. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <string>
using namespace std;

#define SIZE 20


class HashEntry {
private:
    string key;
    string value;
    
public:
    HashEntry(string key, string value) {
        this->key = key;
        this->value = value;
    }
    string getKey() {
        return key;
    }
    string getValue() {
        return value;
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
    
    string get (string key) {
        string::iterator it, it2;
        it = key.begin();
        it = key.end();
        int hash;
        hash = (*it + *it2) % SIZE;
        
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % SIZE;
        
        if (table[hash] == nullptr) {
            return nullptr;
        } else {
            return table[hash]->getValue();
        }
    }
    
    void put(string key, string value) {
        string::iterator it, it2;
        it = key.begin();
        it = key.end();
        int hash;
        hash = (*it + *it2) % SIZE;
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % SIZE;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }
    
    };


#endif /* HashTable_h */
