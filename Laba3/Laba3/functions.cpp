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
int opPreced(const char ch)
{
    if(ch=='*'||ch=='/')return 3;
    else if(ch=='+'||ch=='-')return 2;
    else if(ch=='(')return 1;
    else if(ch==')')return -1;
    else return 0;
}
string Postfix(string s,int priority,stackch Operations,int num,int num1,char ch,string resmas){
    for(int i=0;i<s.length();i++){
        if(s[i]==' ')i++;
        if(isdigit(s[i])){
            resmas+=s[i];
            num++;
        }
        else {
            if(opPreced(s[i])<=priority){
                pop1(Operations, ch);
                resmas+=ch;
                num1--;
            }
            priority=opPreced(s[i]);
            push1(Operations,s[i]);
            num1++;
        }
    }
    for(int i=0;i<num1;i++){
        pop1(Operations, ch);
        resmas+=ch;
    }
    cout<<"postfix notation:"<<resmas<<endl;
    return resmas;
}

void ResultExp(string s,stack Number,int result,string resmas){
    string N;
    int value=0;
    for(int i=0;i<resmas.length();i++){
        if(isdigit(resmas[i])){
            N=resmas[i];
            push(Number, stoi(N));
        }
        else if(resmas[i]=='*'){
            pop(Number, value);
            result=value;
            pop(Number, value);
            result*=value;
            push(Number, result);
        }
        else if(resmas[i]=='/'){
            pop(Number, value);
            result=value;
            pop(Number, value);
            result=value/result;
            push(Number, result);
        }
        else if(resmas[i]=='+'){
            pop(Number, value);
            result=value;
            pop(Number, value);
            result+=value;
            push(Number, result);
        }
        else if(resmas[i]=='-'){
            pop(Number, value);
            result=-value;
            pop(Number, value);
            result+=value;
            push(Number, result);
        }
    }
    pop(Number, value);
    result=value;
    cout<<"result:"<<result<<endl;
}
