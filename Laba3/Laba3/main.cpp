#include <iostream>
#include <string>
#include "Header.h"
int main(int argc, char* argv[]) {
    string s;
    s=argv[1];
    int result=0;
    char ch = '\0';
    string resmas="";
    int num=0;
    int num1=0;
    stack Number;
    stackch Operations;
    int priority=0;
    resmas=Postfix(s, priority, Operations, num, num1, ch, resmas);
    ResultExp(s, Number, result, resmas);
    return 0;
}
