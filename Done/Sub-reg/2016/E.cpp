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
typedef pair<int,ll> pll;

const int MAXN=112;
const int MAXV=(1<<16) + 10;
const ll  INF=0x3f3f3f3f3f3f3f3fll;
const ll  MOD=1000000007;

int n, ind[MAXV];
string p[MAXN];
vector<pll> adj[MAXV];
ll val[MAXV];
vector<int> toposort;
ll min_dist[MAXV], max_dist[MAXV];
ll comb[20], fat[20], inv[20];
bool ignored[20];
int calc[20];

ll HexDec(string s) {
  int tam = s.size();
  ll ret = 0;
  ll pow = 1;
  for(int i = (tam - 1); i >= 0; i--) {
    if(s[i] >= '0' && s[i] <= '9') {
      ret += (s[i] - '0')*pow;
    }
    else {
      ret += (s[i] - 'a' + 10)*pow;
    }
    pow *= (1<<4);
  }
  return ret;
}

int ValHex(char x) {
  if(x >= '0' && x <= '9') return (x - '0');
  else return (x - 'a' + 10);
}

string DecHex(ll x) {
  int dig = 0;
  while(x/(1LL<<(4*dig))) dig++;
  if(dig == 0) return "0";
  string ret = "";
  for(int i = (dig - 1); i >= 0; i--) {
    int car = x/(1LL<<(4*i));
    if(car < 10) {
      char add = '0' + car;
      ret += add;
    }
    else {
      char add = 'a' - 10 + car;
      ret += add;
    }
    x %= (1LL<<(4*i));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  n = HexDec(s);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  inv[16] = 16;
  fat[1] = 1;
  for(int i = 2; i <= 16; i++)
    fat[i] = i*fat[i-1];
  
  comb[0] = comb[16] = 1;
  for(int i = 1; i <= 15; i++)
    comb[i] = (fat[16]/(fat[16 - i]*fat[i]));

  for(int i = 1; i <= 16; i++)
    calc[i] = (fat[16]/comb[i])%MOD;
  
  ll tot = 0;
  ll lim = (ll)1e16;
  memset(val, 0, sizeof(val));
  for(int i = 1; i < (1<<16); i++) {
    min_dist[i] = INF;
    max_dist[i] = -INF;

    for(int k = 0; k < 16; k++) ignored[k] = false;
    for(int k = 0; k < 16; k++) {
      if(i&(1<<k))
	ignored[k] = true;
    }

    for(int k = 0; k < n; k++) {
      ll pal = 0;
      int num = 0;
      int tam = p[k].size();
      for(int j = (tam - 1); j >= 0; j--) {
	int g = ValHex(p[k][j]);
	if(!(ignored[g])) {
	  pal += ((ll)g)*(1LL<<(4*num));
	  ++num;
	}
      }
      val[i] += pal;
    }
    //    debug("--> %lld\n", val[i]);
    int b = __builtin_popcount(i);
    tot += ((val[i]%MOD)*(calc[b]));
    if(tot >= lim) tot %= MOD;
      
    for(int k = 0; k < 16; k++) {
      if(i&(1<<k)) {
	int v = i - (1<<k);
	adj[v].pb(mp(i, val[i]));
	ind[i]++;
      }
    }
  }
  queue<int> ver;
  ver.push(0);
  while(!ver.empty()) {
    int u = ver.front();
    toposort.pb(u);
    for(auto e : adj[u]) {
      int v = e.first;
      ind[v]--;
      if(ind[v] == 0) ver.push(v);
    }
    ver.pop();
  }
  min_dist[0] = 0;
  max_dist[0] = 0;
  for(int u : toposort) {
    for(auto e : adj[u]) {
      int v = e.first;
      ll w = e.second;
      min_dist[v] = min(min_dist[v], min_dist[u] + w);
      max_dist[v] = max(max_dist[v], max_dist[u] + w);
    }
  }
  tot %= MOD;
  cout << DecHex(min_dist[(1<<16) - 1]) << ' ' << DecHex(max_dist[(1<<16) - 1]) << ' ' << DecHex(tot) << '\n';
  return 0;
}
