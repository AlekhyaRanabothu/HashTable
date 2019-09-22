#include "SList.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


//constructor initializing M for size of array and aarray of LNodes HT
SList::SList() {
    M=88801;
    HT = new LNode[M];
}
//Destructor
SList::~SList() {
    for(int i=1;i <=M;i++)
    {
        HT[i].head = nullptr;
        HT[i].next = nullptr;
        HT[i].tail = nullptr;
    }
           delete HT;
    cout<<"Hash table is deleted"<<endl;
}
//add function inserts using djb2 if n=1, using sdbm otherwise
//it sfinds the key value using j=hfunc function and if it is empty,it assigns name and id to it
//and akes it both head and tail
//else it adds the node to tail and updates the tail
int SList::add(string k1,int n) {
    if(search(k1,n)!=-1){
        return -1;
    }
    char k[1024];
    strcpy(k, k1.c_str());
    int j=((hfunc(k,n) % M) + M) % M;
    if(j==HT[j].ht.getd()){

        LNode *temp=new LNode;
        temp->ht.setd(((hfunc(k,n) % M) + M) % M);
        temp->ht.setln(k1);
        HT[j].tail->next=temp;
        HT[j].tail=HT[j].tail->next;
        return 1;
    }

    LNode temp;
    HT[j]=temp;
    HT[j].ht.setd(((hfunc(k,n) % M) + M) % M);
    HT[j].ht.setln(k);
    HT[j].head=&HT[j];
    HT[j].tail=&HT[j];
    return 1;


}
//printHT() for printing the table to console
void SList::printHT() {
    int i=0;
    cout<<"******************************"<<endl;
    while(i<88801){
        if(HT[i].ht.getd()!=-1){
            cout<<i<<" ";
            cout<<HT[i].ht.getname();
            LNode *temp=&HT[i];
            while(temp->next!= nullptr){
                temp=temp->next;
                cout<<"---"<<temp->ht.getname();
            }
            cout<<endl;
        }
        i++;
    }
    cout<<"******************************"<<endl;
}
//remove searches for element, if not found,displays message.If found it deals with 3 cases
//1 the element is head then remove it and make the next element as head
//2 the tail is head then remove it and update tail to its previous element
//3 if it is not from the above cases, set next of previous element to thre next element.
void SList::remove(string s1,int n) {
    char s[1024];
    strcpy(s, s1.c_str());
    int j=search(s1,n);
    //cout<<1<<endl;
    if(j!=-1){
        if(((hfunc(s,n) % M) + M) % M==HT[j].ht.getd()){
            if(HT[j].next== nullptr){
                HT[j].head= nullptr;
                HT[j].tail= nullptr;
                HT[j].ht.setd(-1);
                HT[j].ht.setln("");
                cout<<"Record deleted"<<endl;
                return;
            }
            LNode temp;
            temp.ht.setd(HT[j].next->ht.getd());
            temp.ht.setln(HT[j].next->ht.getname());
            temp.next=HT[j].next->next;
            LNode *t2=&HT[j];
            if(HT[j].tail->ht.getname()==s1){
                LNode *p2=t2;
                t2=t2->next;
                while(t2->next!= nullptr){
                    p2=t2;
                    t2=t2->next;
                }
                p2->next= nullptr;
                HT[j].tail=p2;
                cout<<"Record deleted"<<endl;
                return;
            }

            if(HT[j].ht.getname()==s1){
                HT[j].head=&temp;
                HT[j]=temp;
                cout<<"Record deleted"<<endl;
                return;
            }
            LNode *temp2=&HT[j];
            while(1){
                LNode *prev=temp2;
                temp2=temp2->next;
                if(temp.ht.getname()==s1){
                    prev->next=temp2->next;
                    cout<<"Record deleted"<<endl;
                    return;
                }

            }
        }
    }
    else{
        cout<<"Record cannot be deleted"<<endl;
    }
}
//finds key value and goes to the element in array and traverses through the linked list if found,return bucket and print it
//else print and return -1
int SList::search(string s1,int n) {
    char s[1024];
    strcpy(s, s1.c_str());
    int h=((hfunc(s,n) % M) + M) % M;
    int i=88801;
    if(h==HT[h].ht.getd()){
        LNode *temp=&HT[h];
        if(HT[h].ht.getname()==s1){
            return h;
        }
        while(temp->next!= nullptr){
            temp=temp->next;
            if(temp->ht.getname()==s1){

                return h;
            }


        }
    }
    return -1;

}
//hfunc gives key value using djbe =2 if n=1 and sdbm otherwise
long SList::hfunc(char *s,int n) {
    HashTable *hsh=new HashTable;
    if(n==1){
        return hsh->djb2(s);
    }
    else{
        return hsh->sdbm(s);
    }

}
//traverses through array and if ther is an Lnode, then traverses through linked list and saves the output to file
void SList::save(char *s){
    ofstream myfile;
    myfile.open(s);
    int i=0;
    int c=0;//for counting the bucket size
    while(i<88801){
        if(HT[i].ht.getd()!=-1){
            c++;
            myfile<<i<<" ";
            myfile<<HT[i].ht.getname();
            LNode *temp=&HT[i];
            while(temp->next!= nullptr){
                temp=temp->next;
                myfile<<"---"<<temp->ht.getname();

            }
            myfile<<"\n";
        }
        else{
            myfile<<i<<" Empty"<<"\n";
        }
        i++;
    }

    myfile.close();
    cout<<"Log file saved"<<"Bucket size is"<<c<<endl;
}