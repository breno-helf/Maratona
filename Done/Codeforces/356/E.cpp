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

int low[MAXN][MAXN], d[MAXN][MAXN], sn, quand, num, add[MAXN*MAXN];

int sz[MAXN*MAXN], nsz[MAXN*MAXN];

pii cmp[MAXN][MAXN];

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
    nxt.clear();
    while( !(a==x && b==y) ){
      a = st[sn-1].first;
      b = st[sn-1].second;
      cur++;
      d[a][b] = INF;
      --sn;
      nxt.pb(mp(a,b));
    }
    int tam = nxt.size();
    for(int i=0;i<tam;i++) cmp[nxt[i].first][nxt[i].second].first = cur, cmp[nxt[i].first][nxt[i].second].second = num;
    nsz[num] = sz[num] = cur;
    num++;
  }
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i=1;i<=n;i++){
    getchar();
    for(int j=0;j<n;j++){
      char gg = getchar();
      if(gg == 'X') g[i][j+1] = 1;
    }
  }

  resp = 0;
  num = 1;
  int t = 1;

  for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(!marc[i][j] && !g[i][j]) scc(i,j);

  for(int a=1;a+k-1<=n;a++){
    for(int i=0;i<num;i++) sz[i] = nsz[i];

    for(int i=0;i<k;i++) for(int j=1;j<=k;j++) if(!g[a+i][j]) sz[cmp[a+i][j].second]--;

    for(int b=1;b+k-1<=n;b++){
      int atual = k*k;
      for(int i=0;i<k;i++){
	int ni, nj;
	ni = a-1, nj = b + i;
	if(ver(ni,nj)){
	  if(!g[ni][nj]){
	    if(add[cmp[ni][nj].second] != t) atual += sz[cmp[ni][nj].second], add[cmp[ni][nj].second] = t;
	  }
	}
	ni = a + i, nj = b + k;
	if(ver(ni,nj)){
	  if(!g[ni][nj]){
	    if(add[cmp[ni][nj].second] != t) atual += sz[cmp[ni][nj].second], add[cmp[ni][nj].second] = t;
	  }
	}
	ni = a + k, nj = b + i;
	if(ver(ni,nj)){
	  if(!g[ni][nj]){
	    if(add[cmp[ni][nj].second] != t) atual += sz[cmp[ni][nj].second], add[cmp[ni][nj].second] = t;
	  }
	}
	ni = a + i, nj = b -1;
	if(ver(ni,nj)){
	  if(!g[ni][nj]){
	    if(add[cmp[ni][nj].second] != t) atual += sz[cmp[ni][nj].second], add[cmp[ni][nj].second] = t;
	  }
	}
      }
      resp = max(resp, atual);
      for(int i = a; i<a+k;i++){
	if(!g[i][b]) sz[cmp[i][b].second]++;
	if((b+k)<=n && !g[i][b+k]) sz[cmp[i][b+k].second]--;
      }
      t++;
    }
  }
  
  printf("%d\n", resp);
  return 0;
}
