//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int MAXW=50;
const int INF=0x3f3f3f3f;

char s[MAXN][MAXW];
char resp[MAXW];
int n, tam;

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%s", s[i]);
  for(int j=0;j<n;j++){
    strcpy(resp,s[j]);
    tam = strlen(resp);
    int ss = 1;
    for(int i=0;i<n;i++){
      int d = 0;
      for(int k=0;k<tam;k++) if(s[i][k]!=resp[k]) d++;
      if(d>1) ss=0;
    }
    if(ss) break;
  }						  
  printf("%s\n", resp);
  return 0;
}
  


