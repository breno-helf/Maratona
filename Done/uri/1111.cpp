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

const int MAXN=22;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n;

int g[MAXN][MAXN][4];
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

int dist[MAXN][MAXN][MAXN][MAXN];

int main() {
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;
    memset(dist, INF, sizeof(dist));
    memset(g, 0, sizeof(g));
    for(int i = n - 1; i >= 0; i--) {
      for(int j = 0; j < n; j++) {
	dist[i][j][i][j] = 0;
	for(int k = 0; k < 4; k++) scanf("%d", &g[i][j][k]);
      }
    }
    for(int i = n - 1; i >= 0; i--) {
      for(int j = 0; j < n; j++) {
	debug("[-->] init %d %d\n", i, j);
	queue<pii> q;
	q.push(pii(i,j));
	while(!q.empty()) {
	  int x = (q.front()).first;
	  int y = (q.front()).second;
	  debug("%d %d\n", x, y); 
	  for(int k = 0; k < 4; k++) {
	    if(g[x][y][k]) {
	      if(dist[i][j][x + dy[k]][y + dx[k]] > dist[i][j][x][y] + 1) {
		dist[i][j][x + dy[k]][y + dx[k]] = dist[i][j][x][y] + 1;
		q.push(pii(x + dy[k], y + dx[k]));
	      }
	    }
	  }
	  q.pop();
	}
      }
    }
    
    for(int i = n-1; i >= 0; i--) {
      for(int j = 0; j < n; j++) {
	debug("%d ", dist[n-1][0][i][j]);
      }
      debug("\n");
    }
    
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      int resp = dist[b][a][d][c];
      if(resp != INF) printf("%d\n", resp);
      else puts("Impossible");
    }
    putchar('\n');
  }
}
