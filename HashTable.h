#ifndef _HashTable_
#define _HashTable_

#include <string>


using namespace std;
class HashTable {
public:
    HashTable();
    ~HashTable();
    string getname();
    long getd();
    void setln(string s);
    void setd(long i);
    long djb2(char* s);
    long sdbm(char* s);
private:
    string lname;
    long d;

};
#endif
