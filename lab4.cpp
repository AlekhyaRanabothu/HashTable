#include "SList.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <ctime>
using namespace std;
int main() {
    char t[1024];
    //2 hash tables HT1 for djbe,HT2 for sdbm
    SList *HT1=new SList();
    SList *HT2=new SList();
    //read file and insert using add function

    ifstream lasts;
    lasts.open("all.last.txt");
    string line;

    if (lasts.is_open())
    {
        clock_t time_req;
        while ( getline (lasts,line) )
        {
            HT1->add(line,1);
            //HT2->add(line,2);
        }
        lasts.close();
        time_req = clock() - time_req;
        cout << "Using djb2 function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    }
    ifstream lasts1;
    lasts1.open("all.last.txt");
    string line1;

    if (lasts1.is_open())
    {
        clock_t time_req;
        while ( getline (lasts1,line1) )
        {
            //HT1->add(line,1);
            HT2->add(line1,2);
        }
        lasts.close();
        time_req = clock() - time_req;
        cout << "Using sdbm function, it took " << (float)time_req/CLOCKS_PER_SEC << " seconds" << endl;
    }
    else cout << "Unable to open file";
    string s;
    //display menu
    while(1) {
        cout << "MENU" << endl;
        cout << "(A1)Add record to djb2 Hash table" << endl;
        cout << "(A2)Add record to sdbm Hash table" << endl;
        cout << "(D1)Delete from djb2 Hash table" << endl;
        cout << "(D2)Delete from sdbm Hash table" << endl;
        cout << "(S1)Search from djb2 Hash table" << endl;
        cout << "(S2)Search from sdbm Hash table" << endl;
        cout << "(L1)Save djb2 Hash table to log file" << endl;
        cout << "(L2)Save sdbm Hash table to log file" << endl;
        cout << "(Q)uit" << endl;
        cout<<"Enter your choice from the menu : "<<endl;
        cin>>s;
        if(s=="A1" || s=="A2"){
            int n=1;
            if(s=="A2"){
                n=2;
            }
            string ln;
            cout<<"Enter the last name : "<<endl;
            cin>>ln;
            if(n==1){
                int w1=HT1->add(ln,n);
                if(w1==1){
                    cout<<"Record added"<<endl;
                }
                else{
                    cout<<"Duplicate record"<<endl;
                }
            }
            else{
                int w2=HT2->add(ln,n);
                if(w2==1){
                    cout<<"Record added"<<endl;
                }
                else{
                    cout<<"Duplicate record"<<endl;
                }
            }
        }
        else if(s=="D1" || s=="D2"){
            int n=1;
            if(s=="D2"){
                n=2;
            }
            string ln;
            cout<<"Enter the last name to delete : "<<endl;
            cin>>ln;
            if(n==1){
                HT1->remove(ln,n);
            }
            else{
                HT2->remove(ln,n);
            }

        }
        else if(s=="S1" || s=="S2"){
            int n=1;
            if(s=="S2"){
                n=2;
            }
            string ln;
            cout<<"Enter the last name to search : "<<endl;
            cin>>ln;
            if(n==1){
                int w=HT1->search(ln,n);
                if(w!=-1){
                    cout<<w<<endl;
                    cout<<"Bucket number : "<<w<<endl;
                }
                else{
                    cout<<"Not found"<<endl;
                }
            }
            else{
                int w4=HT2->search(ln,n);
                if(w4!=-1){
                    cout<<w4<<endl;
                    cout<<"Bucket number : "<<w4<<endl;
                }
                else{
                    cout<<"Not found"<<endl;
                }
            }
        }
        else if(s=="L1" || s=="L2"){
            if(s=="L1"){
                strcpy(t,"HT1.txt");
                HT1->save(t);

                cout<<"Log file saved for djb2 Hash Table(HT1.txt)"<<endl;
            }
            else{
                strcpy(t,"HT2.txt");
                HT2->save(t);
                cout<<"Log file saved for sdbm Hash Table(HT2.txt)"<<endl;
            }

        }
        else if(s=="Q"){
            delete HT1;
            delete HT2;
            break;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
        cout<<" "<<endl;

    }
    return 0;
}