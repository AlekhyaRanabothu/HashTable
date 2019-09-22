#include "HashTable.h"
#include <iostream>
using namespace std;
HashTable::HashTable()
{
    lname="";
    d=-1;
}
HashTable::~HashTable()
{

}
//djb2 hash code function
long HashTable::djb2(char *s) {
    unsigned long hash = 5381;
    int c;

    while (c = *s++)
        hash = ((hash << 5) + hash) + c;/* hash * 33 + c */

    return hash;
}
//sdbm hash code function
long HashTable::sdbm(char *s) {
    unsigned long hash = 0;
    int c;
    while (c = *s++)
        hash = c + (hash << 6) + (hash << 16) - hash;

    return hash;
}
//getter setter methods for name and d which is the key value(-1 by default)
string HashTable::getname(){
    return lname;
}
long HashTable::getd(){
    return d;
}
void HashTable::setln(string s){
    lname=s;
}
void HashTable::setd(long i){
    d=i;
}