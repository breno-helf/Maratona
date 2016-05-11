#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 205;
 
char expression[MAXN];

stack<int> pilha;

int main(){
    for(int i = 0; i < MAXN; i++) expression[i] = 0;
   
    scanf("%s", expression);
   
    int size=strlen(expression);
   
    for(int i = 0; i < size; i++) if(expression[i] == '[') pilha.push(i);
   
    while(!pilha.empty()){
      int it = pilha.top();
           
      while(true){
	if(expression[it] == '[') expression[it] = '(';
               
	else if(expression[it] == ']'){ expression[it] = ')'; break;}
               
	else if(expression[it] >= 'a' && expression[it] <= 'z') expression[it] -= 'a'-'A';
	else if(expression[it] >= 'A' && expression[it] <= 'Z') expression[it] += 'a'-'A';
               
	else if(expression[it] == '+') expression[it]='*';
	else if(expression[it] == '*') expression[it]='+';
               
	it++;
      }
           
      pilha.pop();
    }
    for(int i = 0; i < size; i++) printf("%c", expression[i]);
    printf("\n");
    return 0;
}
