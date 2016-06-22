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
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll  MOD=1000000007;

vector<pii> adj[MAXN];

int n, a[MAXN], sub[MAXN], resp, pai[MAXN];

ll d[MAXN];

void sz(int u){
  for(auto e : adj[u]){
    if(e.first!=(pai[u])){
      pai[e.first] = u;
      sz(e.first);
      sub[u] += sub[e.first];
    }
  }
}

void dfs(int u){
  for(auto e : adj[u]){
    if(e.first!=(pai[u])){
      pai[e.first] = u;
      d[e.first] = d[u] + e.second;
      if(d[e.first] < 0) d[e.first] = 0;
      debug("[-->] V %d dist %lld\n", e.first, d[e.first]);
      if(d[e.first] > a[e.first]) resp += sub[e.first];
      else dfs(e.first);
    }
  }
}

  

int main(){
  scanf("%d", &n);
  resp = 0;
  for(int i=1;i<=n;i++){
    pai[i] = i;
    sub[i] = 1;
    d[i] = -INF;
  }
  d[1] = 0;
  for(int i=1;i<=n;i++) scanf("%d", a+i);
  for(int i=1;i<n;i++){
    int z, x;
    scanf("%d%d", &z, &x);
    adj[i+1].pb(mp(z,x));
    adj[z].pb(mp(i+1,x));
  }
  sz(1);
  for(int i=1;i<=n;i++) pai[i] = i;
  dfs(1);
  printf("%d\n", resp);
  return 0;
}
  
