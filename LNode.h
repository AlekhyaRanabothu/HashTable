#include <string>
#ifndef HASH_LNODE_H
#define HASH_LNODE_H

#include "HashTable.h"
using namespace std;
class LNode {
public:
    HashTable ht;
    LNode *next;
    LNode *head;
    LNode *tail;
    LNode(HashTable ht1){
        ht=ht1;
        next=NULL;
        head=NULL;
        tail=NULL;
    }

    LNode(){
        next=NULL;
        head=NULL;
        tail=NULL;
    }


};
#endif //HASH_LNODE_H
