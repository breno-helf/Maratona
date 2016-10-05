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

const int MAXN=212;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, t, used, nxt;
set<int> adj[MAXN];
pii ed[MAXN*MAXN];
int dir[MAXN*MAXN];

void dfs(int u, int d, bool s) {
  if(u == d && !s) return;
  pii use;
  int idx;
  for(auto i : adj[u]) {
    if(ed[i].first == u) {
      dir[i] = 2;
      use = ed[i];
      idx = i;
      break;
    }
    else {
      dir[i] = 1;
      use = ed[i];
      idx = i;
      break;
    }
  }
  used++;
  adj[use.first].erase(idx);
  adj[use.second].erase(idx);
  if(adj[u].size() > 0) nxt = u;
  
  if(dir[idx] == 1)
    dfs(use.first, d, 0);
  else
    dfs(use.second, d, 0);
  
}

int main() {
  for(scanf("%d", &t); t; t--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) adj[i].clear();
    memset(ed, 0, sizeof(ed));
    memset(dir, 0, sizeof(dir));
    used = 0;
    for(int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      ed[i] = pii(a, b);
      adj[a].insert(i);
      adj[b].insert(i);
    }
    vector<int> imp;
    for(int i = 1; i <= n; i++)
      if((adj[i].size())%2) imp.pb(i);
    int tam = imp.size();
    for(int i = 0; i < tam; i += 2) {
      int a, b, idx;
      a = imp[i], b = imp[i + 1], idx = m + (i/2);
      ed[idx] = pii(a, b);
      adj[a].insert(idx);
      adj[b].insert(idx);
    }
    for(int i = 1; i <= n; i++) {
      nxt = i;
      while(adj[nxt].size() > 0)
	dfs(nxt, nxt, 1);
    }
    printf("%d\n", n - tam);
    for(int i = 0; i < m; i++) {
      if(dir[i] == 1)
	printf("%d %d\n", ed[i].second, ed[i].first);
      else
	printf("%d %d\n", ed[i].first, ed[i].second);
    }
  }
}



