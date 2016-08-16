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

const int MAXN=11234;
const int MAXP=23;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int h[MAXN], n;

pii pre[MAXN][MAXP], pai[MAXN];

string op[3] = {"DIST", "KTH", "DONE"};

vector<pii> adj[MAXN];

void dfs(int x, int u) {
  for(auto& v : adj[x]) {
    int nxt = v.first, e = v.second;
    if(nxt != u) {
      h[nxt] = h[x] + 1;
      pai[nxt] = mp(x,e);
      dfs(nxt, x);
    }
  }
}

void precalc() {
  for(int i = 1; i <= n; i++) pre[i][0] = pai[i];

  for(int k = 1; k < MAXP; k++) {
    for(int i = 1; i <= n; i++) {
      pre[i][k] = mp(pre[ pre[i][k-1].first ][k-1].first, pre[i][k-1].second + pre[ pre[i][k-1].first ][k-1].second);
    }
  }
}

int dist(int x, int y) {
  int ret = 0;
  if(h[x] > h[y]) swap(x,y);
  int dif = h[y] - h[x];

  for(int i = 21; i >= 0; i--) {
    if((1<<i) <= dif) {
      ret += pre[y][i].second;
      y = pre[y][i].first;
      dif -= (1<<i);
    }
  }

  if(x == y) return ret;

  for(int i = 21; i >= 0; i--) {
    if(pre[x][i].first != pre[y][i].first) {
      ret += pre[x][i].second + pre[y][i].second;
      x = pre[x][i].first;
      y = pre[y][i].first;
    }
  }

  ret += pre[x][0].second + pre[y][0].second;

  return ret;

}
      
int kth(int x, int y, int k) {
  int start = x, end = y;
  
  if(h[x] > h[y]) swap(x,y);
  int dif = h[y] - h[x];
  
  for(int i = 21; i >= 0; i--) {
    if((1<<i) <= dif) {
      y = pre[y][i].first;
      dif -= (1<<i);
    }
  }

  if(x != y) {
    for(int i = 21; i >= 0; i--) {
      if(pre[x][i].first != pre[y][i].first) {
	x = pre[x][i].first;
	y = pre[y][i].first;
      }
    }
    y = pre[y][0].first;
  }
  int lca = y;

  if(lca == end) {
    int ret = start;
    for(k = k; k > 1; k--)
      ret = pai[ret].first;
    return ret;
  }
  
  if(k < (h[start] - h[lca] + 1)) {
    int hk = h[start] - k + 1;

    int ret = start;
    
    for(int i = 21; i >= 0; i--)
      if(h[pre[ret][i].first] >= hk) ret = pre[ret][i].first;

    return ret;
  }

  if(k == (h[start] - h[lca] + 1)) return lca;

  else {
    int hk = k - h[start] + h[lca] + h[lca] - 1;
    int ret = end;

    for(int i = 21; i >= 0; i--)
      if(h[pre[ret][i].first] >= hk) ret = pre[ret][i].first;

    return ret;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    
    cin >> n;
    for(int i = 0; i <= 10000; i++) {
      adj[i].clear();
    }
    memset(pai,0,sizeof(pai));
    memset(h,0,sizeof(h));
    memset(pre,0,sizeof(pre));

    for(int i = 1; i < n; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].pb(mp(b,c));
      adj[b].pb(mp(a,c));
    }

    pai[1] = mp(1, 0);
    dfs(1, 1);

    precalc();

    while(1) {
      string s;
      cin >> s;
      if(s == op[0]) {
	int a, b;
	cin >> a >> b;
	cout << dist(a,b) << '\n';
      }
      if(s == op[1]) {
	int a, b, c;
	cin >> a >> b >> c;
	cout << kth(a,b,c) << '\n';
      }
      if(s == op[2]) break;
    }
  }
  return 0;
}
