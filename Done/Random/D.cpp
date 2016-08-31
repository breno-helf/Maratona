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
const ll  INF=(ll)1e17;
const ll  MOD=1000000007;

int n, t, p[MAXN];

ll dist[MAXN];

vector<pll> adj[MAXN];

vector<ll> leaves;

map<int,int> nor;

void dfs(int u) {
  int tam = adj[u].size();
  ll men = INF;
  for(int i = 0; i < tam; i++){
    ll c = adj[u][i].first;
    if(c < men){
      men = c;
    }
  }

  for(int i = 0; i < tam; i++){
    ll v = adj[u][i].second, c = adj[u][i].first;
    if(v != p[u]){
      dist[v] = dist[u] + 2*c - men;
      dfs(v);
    }
  }
}


int main(){
  scanf("%d", &t);
  while(t--) {
    nor.clear();
    scanf("%d", &n);
    for(int i = 0; i < MAXN; i++){
      p[i] =  0;
      dist[i] = INF;
      adj[i].clear();
    }
    leaves.clear();
    p[1] = 1;
    dist[1] = 0;
    for(int i = 2; i <= n; i++) {
      ll a, b;
      scanf("%lld%lld", &a, &b);
      p[i] = a;
      nor[a]++;
      adj[a].pb(mp(b,i));
    }

    dfs(1);
    int q;
    for(int i = 1; i <= n; i++) {
      if(nor[i] == 0) leaves.pb(dist[i]);
    }
    sort(leaves.begin(), leaves.end());
    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
      ll tempo;
      scanf("%lld", &tempo);
      int resp = upper_bound(leaves.begin(), leaves.end(), tempo) - leaves.begin();
      printf("%d\n", resp);
    }
  }
  return 0;
}
