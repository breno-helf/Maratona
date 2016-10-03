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

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, k;
char c[MAXN][MAXN];
int marc[MAXN][MAXN], g[MAXN][MAXN];
int low[MAXN][MAXN], d[MAXN][MAXN], qnd;
int sn, sz[MAXN*MAXN], num;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
vector<pii> nxt, p;
pii cmp[MAXN][MAXN], st[MAXN*MAXN], r[MAXN*MAXN];

bool ver(int i, int j) {
  return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void scc(int x, int y, int f) {
  //debug("--> %d %d %d\n", x, y, f);
  st[sn].first = x;
  st[sn++].second = y;
  low[x][y] = d[x][y] = qnd++;
  marc[x][y] = 1;
  for(int i = 0; i < 4; i++){
    int w = x + dx[i], z = y + dy[i];
    if(ver(w,z)){
      if(!marc[w][z] && !g[w][z]){
	scc(w, z, f);
	low[x][y] = min(low[x][y], low[w][z]);
      }
      else if(!g[w][z]){
	low[x][y] = min(low[x][y], d[w][z]);
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
    if(f) {
      int tam = nxt.size();
      for(int i = 0; i < tam; i++) {
	cmp[nxt[i].first][nxt[i].second].first = cur;
	cmp[nxt[i].first][nxt[i].second].second = num;
      }
      sz[num] = cur;
      r[num] = nxt[0];
      num++;
    }
  }  
}

void afoga(int x, int y) {
  c[x][y] = '*';
  for(int i = 0; i < 4; i++) {
    int w = x + dx[i], z = y + dy[i];
    if(ver(w, z)) {
      if(c[x + dx[i]][y + dy[i]] == '.') afoga(x + dx[i], y + dy[i]);
    }
  }

}

int main() {
  int resp = 0;
  num = 0;
  
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= n; i++)
    scanf(" %s", c[i]);
  
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < m; j++)
      if(c[i][j] == '*') g[i][j] = 1;
  
  for(int i = 1; i <= n; i+=(max((n-1), 1))) {
    for(int j = 0; j < m; j++)
      if(c[i][j] == '.') scc(i, j, 0);
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < m; j+=(max((m-1), 1)))
      if(c[i][j] == '.') scc(i, j, 0);
  }
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < m; j++)
      if(c[i][j] == '.' && !marc[i][j]) scc(i, j, 1);

  for(int i = 0; i < num; i++) { 
    p.pb(mp(sz[i], i));
    //debug("==: %d %d\n", sz[i], i);
  }
  //debug("\n");
  if(p.size() > 0) sort(p.begin(), p.end());
  
  for(int i = 0; i < (num - k); i++) {
    resp += p[i].first;
    afoga(r[p[i].second].first, r[p[i].second].second);
  }
  printf("%d\n", resp);
  for(int i = 1; i <= n; i++) {
    printf("%s\n", c[i]);
  }
  return 0;
}



