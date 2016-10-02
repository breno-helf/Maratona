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

const int MAXN=5123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, t;
vector<pii> adj[MAXN];
vector<int> rev;
int ind[MAXN];
pair<int, int> dp[MAXN][MAXN];

void topo() {
  set<int> ver;
  for(int i = 1; i <= n; i++) {
    if(ind[i] == 0) ver.insert(i);
  }
  while(!ver.empty()) {
    int u = *(ver.begin());
    rev.pb(u);
    for(auto e : adj[u]) {
      int v = e.first;
      ind[v]--;
      if(ind[v] == 0) ver.insert(v);
    }
    ver.erase(u);
  }
    
  reverse(rev.begin(), rev.end());
}

void calc(int u, int q) {
  if(u == 0) return;
  printf("%d", u);
  if(u == n) {
    putchar('\n');
    return;
  }
  else {
    putchar(' ');
  }
  calc(dp[u][q].first, q - 1);
}

int main() {
  scanf("%d%d%d", &n, &m, &t);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    adj[a].pb(mp(b,c));
    ind[b]++;
  }
  topo();
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) 
      dp[i][j] = mp(0, INF);
  }
  dp[n][1] = mp(n, 0);
  
  for(int u : rev) {
    if(u == n) continue;
    for(auto e : adj[u]) {
      int v = e.first, w = e.second;
      for(int i = 1; i <= n; i++) {
	int g = dp[v][i].second;
	if((g + w) <= t) {
	  if((g + w) < dp[u][i + 1].second) {
	    dp[u][i + 1] = mp(v, g + w);
	  }
	}
      }
    }
  }
  int mx = 0;
  for(int i = 1; i <= n; i++) if(dp[1][i] != mp(0, INF)) mx = i;
  printf("%d\n", mx);
  calc(1, mx);
  return 0;
}

