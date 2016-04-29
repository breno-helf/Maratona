#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=51234;
const int INF=0x3f3f3f3f;

char s[MAXN][60];
int n;
int idx[MAXN];
char x[110],y[110];

bool cmp(int a, int b){ 
  strcpy(x,s[a]);
  strcat(x,s[b]);
  strcpy(y,s[b]);
  strcat(y,s[a]);
  return strcmp(x,y) < 0;
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%s", s[i]);
    idx[i]=i;
  }
  sort(&idx[0],&idx[n],cmp);
  for(int i=0;i<n;i++){
     printf("%s", s[idx[i]]);
  }
  printf("\n");
  return 0;
}

//abacabaabbabcder

