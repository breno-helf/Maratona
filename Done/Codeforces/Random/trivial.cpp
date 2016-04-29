#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int m,r,a;
int resp[MAXN];
int main(){
  scanf("%d", &m);
  int k=0;
  for(int i=5;i<=435000;i++){
    int aux=i;
    int e=0;
    while(aux%5==0){
      k++;
      aux/=5;
      e++;
    }
    if(e) resp[k]=i;
  }
  if(resp[m]){
    printf("5\n");
    for(int i=resp[m];i<resp[m]+4;i++) printf("%d ", i);
    printf("%d\n", resp[m]+4);
  }
  else printf("0\n");
  return 0;
}


