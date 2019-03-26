#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>
using namespace std;
struct elem{
    int data;
    elem *next;
};
struct stack{
    elem *top;
    stack(void):top(NULL){}
};


struct elemch{
    char data;
    elemch *next;
};
struct stackch{
    elemch *top;
    stackch(void):top(NULL){}
};
void push(stack &a,const int value);
bool pop(stack &a,int &out);
void push1(stackch &a,const char value);
bool pop1(stackch &a,char &out);
int opPreced(const char ch);
#endif 
