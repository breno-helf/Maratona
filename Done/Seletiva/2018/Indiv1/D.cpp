//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
// ------------ 1000000007

vector<int> adj[MAX];
int n, k;
int T;
int c[MAX];
int mrk[MAX];
int cyc;
ll dp[MAX];
stack<int> st;
vector<int> cycles;

int dfs1(int u) {
  int ret = 1;
  mrk[u] = 1;
  for (int v : adj[u]) {
    if (mrk[v] == 0)
      ret += dfs1(v);
  }
  return ret;
}

void dfs2(int u, int p) {
  mrk[u] = 2;
  st.push(u);
  //debug("--> Visiting %d\n", u);
  for (int v : adj[u]) {
    //debug("--> vx %d is looking to vx %d\n", u, v);
    if (mrk[v] == 1) {
      //debug("--> Going from %d to %d\n", u, v);
      dfs2(v, u);
    }
    else if (v != p && mrk[v] == 2) {
      //debug("==> Found cycle at %d %d\n", u, v);
      cyc++;
      while (!st.empty() && st.top() != v) {
	cyc++;
	mrk[st.top()] = 3;
	st.pop();
      }
      mrk[v] = 3;
    }
  }

  mrk[u] = 3;
  if (!st.empty() && st.top() == u) st.pop();
}

ll solve(int cnt) {
  ll &res = dp[cnt];

  if (res != -1) return res;

  if (cnt == 1) return res = 0;
  
  if (cnt == 2) return res = k * (k - 1);
  
  res = ((k - 2) * solve(cnt - 1)) % MOD + ((k - 1) * solve(cnt - 2)) % MOD;
  return res % MOD;
}

ll pot(ll num, int e) {
  ll ret = 1;
  for (int i = 0; i < e; i++) {
    ret = (ret * num) % MOD;
  }
  return ret % MOD;
}

ll calc(ll num) {
  ll ret = k * (ll)pot(k - 1, num - 1);
  return ret % MOD;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(dp, -1, sizeof(dp));
    memset(mrk, 0, sizeof(mrk));
    cycles.clear();
    while (!st.empty()) st.pop();
    
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) adj[i].clear();
    
    for (int i = 0; i < n; i++) {
      scanf("%d", c + i);
      adj[i].pb(c[i]);
      adj[c[i]].pb(i);
    }
    
    ll ans = 1;
    for (int i = 0; i < n; i++) {
      if (!mrk[i]) {
	cyc = 0;
	ll sum = dfs1(i);
	dfs2(i, i);
	
	//debug("Tree of size %lld and cycle %d\n", sum, cyc);
	if (cyc != 0) cycles.pb(cyc);
	
	if (sum != cyc) {
	  if (cyc != 0)
	    ans = (ans * pot(k - 1, sum - cyc)) % MOD;
	  else
	    ans = (ans * calc(sum)) % MOD;
	}
      }
    }

    //debug("--> %lld\n", ans);
    
    for (int cur : cycles) {
      //debug("Calling dp[%d][%d] * %d\n", cur - 1, 1, k);
      ans = (ans * solve(cur)) % MOD;
    }

    printf("%lld\n", ans % MOD);
  }
  return 0;
}

