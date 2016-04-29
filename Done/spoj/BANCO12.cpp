#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int b[14],n,m;
pii c[MAXN];

queue<int> fila;


int main(){
  int resp=0;
  scanf("%d%d", &m, &n);
  for(int i=0;i<n;i++){
    int x,y;
    scanf("%d%d", &x, &y);
    c[i].first=x;
    c[i].second=y;
    fila.push(i);
  }

  for(int k=0;!fila.empty();k++){
    for(int i=0;i<m;i++) b[i]--;
    while((c[fila.front()].first)<=k){
      int p=0;
      for(int i=0;i<m;i++){
	if(b[i]<=0){
	  if((k-c[fila.front()].first)>20) resp++;
	  b[i]=c[fila.front()].second;
	  fila.pop();
	  p++;
	  break;
	}
      }
      if(fila.empty()) break;
      if(!p){
	break;
      }
    }
  }
  printf("%d\n", resp);
}



