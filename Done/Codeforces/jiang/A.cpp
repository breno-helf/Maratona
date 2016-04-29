#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=512;
const int INF=0x3f3f3f3f;

int t,n,m,resp,marc[MAXN],h[MAXN];

vector<int> adj[MAXN];

void bfs(int x){
  queue<pii> fila;
  memset(h,INF,sizeof(h));
  memset(marc,0,sizeof(marc));
  fila.push(make_pair(x,-1));
  h[x]=1;
  int ra=INF;
  while(!fila.empty()){
    int v=(fila.front()).first;
    int p=(fila.front()).second;
    int tam=adj[v].size();
    marc[v]=1;
    int e=0;
    for(int i=0;i<tam;i++){
      int u=adj[v][i];
      if(!marc[u]){
	fila.push(make_pair(u,v));
	h[u]=min(h[u],h[v]+1);
      }
      else if(u!=p){
	debug("Encerrei a bfs analisando %d em %d\n", u, v);
	debug("h1 %d h2 %d\n", h[u], h[v]);
	ra=h[v]+h[u]-1;
	e++;
	break;
      }
    }
    if(e) break;
    fila.pop();
  }
  resp=min(ra,resp);
}
    
      

int main(){
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    scanf("%d%d", &n, &m);
    resp=INF;
    for(int i=0;i<=n;i++) adj[i].clear();
    memset(marc,0,sizeof(marc));
    for(int i=0;i<m;i++){
      int a,b;
      scanf("%d%d", &a, &b);
      adj[a].pb(b);
      adj[b].pb(a);
    }
    for(int i=0;i<n;i++) bfs(i);
    printf("Case %d: ",tt);
    if(resp>=INF){
      printf("impossible\n");
      continue;
    }
    printf("%d\n", resp);
  }
  return 0;
}
