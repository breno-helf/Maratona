#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=3123;
const int INF=0x3f3f3f3f;

int dist[MAXN][MAXN];
int n,m,marc[MAXN];

int dix[MAXN][3],diy[MAXN][3];
int resp[4],mx;

vector<int> adj[MAXN];

void bfs(int x){
  queue<int> q;
  q.push(x);
  dist[x][x]=0;
  memset(marc,0,sizeof(marc));
  marc[x]=1;
  while(!(q.empty())){
    int v = q.front();
    int tam=adj[v].size();
    for(int k=0;k<tam;k++){
      int w=adj[v][k];
      if(!marc[w]){
	dist[x][w]=dist[x][v]+1;
	q.push(w);
	marc[w]=1;
      }
    }
    q.pop();
  }
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d", &a, &b);
    if(a==b) continue;
    adj[a].pb(b);
  }
  memset(dist,-1,sizeof(dist));
  for(int i=1;i<=n;i++){
    bfs(i);
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i!=j){
	if(dist[i][j]>dist[i][dix[i][0]]){
	  if(dist[i][j]>dist[i][dix[i][1]]){
	    if(dist[i][j]>dist[i][dix[i][2]]){
	      dix[i][0]=dix[i][1];
	      dix[i][1]=dix[i][2];
	      dix[i][2]=j;
	    }
	    else{
	      dix[i][0]=dix[i][1];
	      dix[i][1]=j;
	    }
	  }
	  else{
	    dix[i][0]=j;
	  }
	}
	if(dist[i][j]>dist[diy[j][0]][j]){
	  if(dist[i][j]>dist[diy[j][1]][j]){
	    if(dist[i][j]>dist[diy[j][2]][j]){
	      diy[j][0]=diy[j][1];
	      diy[j][1]=diy[j][2];
	      diy[j][2]=i;
	    }
	    else{
	      diy[j][0]=diy[j][1];
	      diy[j][1]=i;
	    }
	  }
	  else{
	    diy[j][0]=i;
	  }
	}
      }
    }
  }
  int atual=0;
  for(int i=1;i<=n;i++){
    debug(" %d", dist[3][i]);
    // debug("%d\ndiy -->",i);
    // for(int k=0;k<3;k++){
    //   debug(" %d", diy[i][k]);
    // }
    // debug("\ndix -->");
    // for(int k=0;k<3;k++){
    //   debug(" %d", dix[i][k]);
    // }
    // debug("\n\n");
  }
  debug("\n");
  //for(int k=0;k<3;k++){
  //for(int l=0;l<3;l++){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      for(int k=0;k<3;k++){
	for(int l=0;l<3;l++){
	  int di=dix[i][k],dj=diy[j][l];
	  int a1=dist[dj][j],a2=dist[j][i],a3=dist[i][di];
	  if((a1+a2+a3)>atual && di!=dj && i!=j && di!=j && dj!=i && dist[j][i]!=-1){
	    resp[0]=dj;
	    resp[1]=j;
	    resp[2]=i;
	    resp[3]=di;
	    atual=(a1+a2+a3);
	  }
	}
      }
    }
  }
  debug("%d\n", atual);
  printf("%d %d %d %d\n", resp[0], resp[1], resp[2], resp[3]);

  
  return 0;
}
