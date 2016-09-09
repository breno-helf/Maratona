//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=112345;
const int MAXP=25;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, q;
int sz[MAXN]; 
pii pre[MAXN][MAXP];
int p[MAXN], h[MAXN];
vector< pair<int, pii> > ed;
vector<pii> adj[MAXN];

int raiz(int x) {
  if(x == p[x]) return x;
  else return p[x] = raiz(p[x]);
}

void une(int a, int b) {
  a = raiz(a);
  b = raiz(b);
  if(sz[a] < sz[b]) swap(a,b);
  p[b] = a;
  sz[a] += sz[b];
}

void dfs(int x) {

  for(auto v : adj[x]) {
    int nxt = v.first, e = v.second;
    int u = pre[x][0].first;
    if(nxt != u) {
      h[nxt] = h[x] + 1;
      pre[nxt][0] = pii(x,e);
      dfs(nxt);
    }
  }
}

void precalc() {
  for(int k = 1; k < MAXP; k++)
    for(int i = 1; i <= n; i++) {
      pre[i][k] = pii(pre[pre[i][k-1].first][k-1].first, max(pre[pre[i][k-1].first][k-1].second, pre[i][k-1].second));
      //   debug("[-->] %d %d\n", pre[i][k].first, pre[i][k].second);
    } 
}
      
int men(int x, int y) {
  if(h[x] > h[y]) swap(x,y);
  int dif = h[y] - h[x];
  int resp = -1;
  for(int i = MAXP-1; i >= 0; i--) {
    if((1<<i) <= dif) {
      resp = max(resp, pre[y][i].second);
      y = pre[y][i].first;
      dif -= (1<<i);
    }
  }

  if(x != y) {
    for(int i = MAXP-1; i >= 0; i--) {
      if(pre[x][i].first != pre[y][i].first) {
	resp = max(resp, max(pre[x][i].second, pre[y][i].second));
	x = pre[x][i].first;
	y = pre[y][i].first;
      }
    }
    resp = max(resp, max(pre[x][0].second, pre[y][0].second));
  }
  return resp;
}


int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i <= n; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    ed.pb(make_pair(c,pii(a,b)));
  }
  sort(ed.begin(),ed.end());
  for(int i = 0; i < m; i++) {
    int a = ed[i].second.first, b = ed[i].second.second, c = ed[i].first;
    if(raiz(a) != raiz(b)) {
      une(a,b);
      adj[a].pb(pii(b,c));
      adj[b].pb(pii(a,c));
    }
  }
  pre[1][0].first = 1;
  dfs(1);
  precalc();
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if(a == b) puts("0");
    else printf("%d\n", men(a,b));
  }
}
  

