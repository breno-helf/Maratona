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

const int MAXN=512;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

char ss[MAXN];

int n, k, resp, dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool g[MAXN][MAXN], marc[MAXN][MAXN];

vector<pii> nxt;

int low[MAXN][MAXN], d[MAXN][MAXN], sn, quand;

pii st[MAXN*MAXN];

bool ver(int a, int b){
  if(a>=1 && a<=n && b>=1 && b<=n) return 1;
  else return 0;
}

// Tarjan
void scc(int x, int y){
  st[sn].first = x;
  st[sn++].second = y;
  low[x][y] = d[x][y] = quand++;
  marc[x][y] = 1;
  for(int i=0;i<4;i++){
    int w = x+dx[i], z = y + dy[i];
    if(ver(w,z)){
      if(!marc[w][z] && !g[w][z]){
	scc(w,z);
	low[x][y] = min(low[x][y],low[w][z]);
      }
      else if(!g[w][z]){
	low[x][y] = min(low[x][y],d[w][z]);
      }
    }
  }
  if(low[x][y] == d[x][y]){
    int a = -1;
    int b = -1;
    int cur = 0;
    while( !(a==x && b==y) ){
      a = st[sn-1].first;
      b = st[sn-1].second;
      cur++;
      d[a][b] = INF;
      --sn;
    }
    resp = max(resp, cur);
  }
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i=1;i<=n;i++){
    scanf("%s", ss);
    for(int j=0;j<n;j++){
      if(ss[j] == 'X') g[i][j+1] = 1;
    }
  }
  int des = n-k+1;
  resp = 0;
  for(int a=1;a<=des;a++){
    for(int b=1;b<=des;b++){
      nxt.clear();
      for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j] = low[i][j] = 0, marc[i][j] = 0;
      quand = 0;
      sn = 0;
      for(int i = a; i < a+k; i++){
	for(int j = b; j < b+k; j++){
	  if(g[i][j]) g[i][j] = 0, nxt.pb(mp(i,j));
	}
      }
      for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(!marc[i][j] && !g[i][j]) scc(i,j);
      int tam = nxt.size();
      for(int i=0;i<tam;i++) g[nxt[i].first][nxt[i].second] = 1;
    }
  }
  printf("%d\n", resp);
  return 0;
}



