#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

int g[MAXN][MAXN],n,m,q;
int v[MAXN];
int op[11234][4];
int main(){
  scanf("%d%d%d", &n, &m, &q);
  memset(g,INF,sizeof(g));
  for(int i=1;i<=q;i++){
    scanf("%d", &op[i][0]);
    if(op[i][0]==1) scanf("%d", &op[i][1]);
    else if(op[i][0]==2) scanf("%d", &op[i][1]);
    else if(op[i][0]==3) scanf("%d%d%d", &op[i][1], &op[i][2], &op[i][3]);
  }
  for(int i=q;i>0;i--){ 
    if(op[i][0]==1){
      debug("Inverte linha\n");
      int a=op[i][1]-1;
      v[0]=g[a][m-1];
      for(int i=1;i<m;i++) v[i]=g[a][i-1];
      for(int i=0;i<m;i++) g[a][i]=v[i];
    }
    if(op[i][0]==2){
      debug("Inverte Coluna\n");
      int a=op[i][1]-1;
      v[0]=g[n-1][a];
      for(int i=1;i<n;i++) v[i]=g[i-1][a];
      for(int i=0;i<n;i++) g[i][a]=v[i];
    }
    else{
      int x=op[i][1]-1,y=op[i][2]-1,k=op[i][3];
      debug("Valor %d na pos %d %d\n", k, x, y);
      g[x][y]=k;
    }
  }
  for(int i=0;i<n;i++){
    if(g[i][0]==INF) g[i][0]=0;
    printf("%d", g[i][0]);
    for(int j=1;j<m;j++){
      if(g[i][j]==INF) g[i][j]=0;
      printf(" %d", g[i][j]);
    }
    printf("\n");
  }
  return 0;
}
