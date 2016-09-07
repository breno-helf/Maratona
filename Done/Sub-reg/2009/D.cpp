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

const int MAXN=25;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int b, n, resp;

vector<pii> adj[MAXN];
int deg[MAXN];

int din[MAXN], ndin[MAXN];

int main() {
  while(true) {
    resp = 1;
    scanf("%d %d", &b, &n);
    if(b == 0 && n == 0) break;
    for(int i = 1; i <= b; i++) {
      adj[i].clear();
      scanf("%d", &din[i]);
      ndin[i] = din[i];
    }
    for(int i = 0; i < n; i++) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      adj[u].pb(pii(v,w));
      deg[u]++;
      din[v] += w;
    }

    
    for(int i = 1; i <= b; i++) {
      for(auto e : adj[i]) {
	int v = e.first, w = e.second;
	if(w <= din[i]) {
	  deg[i]--;
	  din[i] -= w;
	}
	else resp = 0;
      }
    }
    
    if(resp) puts("S");
    else puts("N");
  }
  return 0;
}

