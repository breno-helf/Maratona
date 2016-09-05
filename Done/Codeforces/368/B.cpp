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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, k;
int s[MAXN];
vector<pii> adj[MAXN];
set<int> a;

int main() {
  int resp = INF;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; i++) {
    int u, v, l;
    scanf("%d%d%d", &u, &v, &l);
    adj[u].pb(pii(v,l));
    adj[v].pb(pii(u,l));
  }
  for(int i = 0; i < k; i++) { 
    scanf("%d", &s[i]);
    a.insert(s[i]);
  }
  for(int i = 0; i < k; i++) {
    for(auto e : adj[s[i]]) {
      if(a.find(e.first) == a.end())
	resp = min(resp, e.second);
    }
  }
  if(resp == INF) puts("-1");
  else printf("%d\n", resp);
  return 0;
}


