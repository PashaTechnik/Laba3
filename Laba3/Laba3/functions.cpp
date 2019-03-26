#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
void push(stack &a,const int value){
    elem *temp=new elem;
    temp->data=value;
    temp->next=a.top;
    a.top=temp;
}
bool pop(stack &a,int &out){
    if(!a.top){
        return false;
    }
    if(!a.top->next){
        out=a.top->data;
        delete a.top;
        a.top=NULL;
        return true;
    }
    elem *del=a.top;
    out=a.top->data;
    a.top=a.top->next;
    delete del;
    return true;
}
void push1(stackch &a,const char value){
    elemch *temp=new elemch;
    temp->data=value;
    temp->next=a.top;
    a.top=temp;
}
bool pop1(stackch &a,char &out){
    if(!a.top){
        return false;
    }
    if(!a.top->next){
        out=a.top->data;
        delete a.top;
        a.top=NULL;
        return true;
    }
    elemch *del=a.top;
    out=a.top->data;
    a.top=a.top->next;
    delete del;
    return true;
}
