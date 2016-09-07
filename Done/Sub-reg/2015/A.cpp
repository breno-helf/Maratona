#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)
#define pb push_back
#define mp make_pair

typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 11234;
const int INF = 0x3f3f3f3f;

int c, ed, resp[MAXN][2];

vector<pii> adj[MAXN];

void dijk(int x) {
  resp[x][0] = 0;
  set< pair<int, pii> > dist;
  dist.insert(mp(0,mp(1,0)));
  while(!dist.empty()) {
    int d = (dist.begin())->first;
    pii sec = ((dist.begin())->second); 
    int u = sec.first;
    int q = sec.second;
    int t = (q+1)%2;
    
    for(auto e : adj[u]) {
      int v = e.first, p = e.second;
      if(resp[v][t] > d + p) {
	if((dist.find(mp(resp[v][t],mp(v,t)))) != dist.end()) {
	  dist.erase(mp(resp[v][t],mp(v,t)));
	  resp[v][t] = resp[u][q] + p;
	  dist.insert(mp(resp[v][t],mp(v,t)));
	}
	else {
	  resp[v][t] = resp[u][q] + p;
	  dist.insert(mp(resp[v][t],mp(v,t)));
	}
      }
    }

    dist.erase(dist.begin());
  }
}

int main() {
  while(scanf("%d%d", &c, &ed) != EOF) {
    memset(resp, INF, sizeof(resp));
    for(int i = 0; i < MAXN; i++) adj[i].clear();
    for(int i = 0; i < ed; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      adj[x].pb(mp(y,z));
      adj[y].pb(mp(x,z));
    }
    dijk(1);
    if(resp[c][0] == INF) puts("-1");
    else printf("%d\n", resp[c][0]);
  }
}
