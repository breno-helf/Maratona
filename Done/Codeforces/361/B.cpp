//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, dist[MAXN], nxt[MAXN], marc[MAXN], fila[MAXN];

vector<int> adj[MAXN];


void bfs(int x){
  marc[x] = 1;
  int ini = 0, fim = 0;
  fila[fim++] = x;
  while(ini<fim){
    int a = fila[ini];
    int tam = adj[a].size();
    for(int i=0;i<tam;i++){

      if(dist[a] + 1 < dist[adj[a][i]]){
	dist[adj[a][i]] = dist[a] + 1;
      }
      if(!marc[adj[a][i]]){
	fila[fim++] = adj[a][i];
	marc[adj[a][i]] = 1;
      }
    }
    ini++;
  }
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    int a;
    scanf("%d", &a);
    adj[i].pb(a);
    if(i>1) adj[i].pb(i-1);
    if(i<n) adj[i].pb(i+1);

    dist[i] = INF;

  }

  dist[1] = 0;
  bfs(1);

  for(int i=1;i<=n;i++){

    printf("%d%c", dist[i], (i==n) ? '\n' : ' ');
  }
}





