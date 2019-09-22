#ifndef HASH_SLIST_H
#define HASH_SLIST_H
#include "LNode.h"
#include "HashTable.h"
class SList {
public:
    SList();
    ~SList();
    int add(string k1,int n);
    void remove(string s,int n);
    int search(string s1,int n);
    void printHT();
    long hfunc(char* s,int n);
    void save(char *s);
private:
    LNode *HT;
    int M;
};


#endif