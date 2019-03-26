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

#endif 
