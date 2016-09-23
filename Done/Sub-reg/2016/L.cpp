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

const int MAXN=500;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int h, l, g[MAXN][MAXN], dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
int marc[MAXN][MAXN], resp;

bool can(int q, int w) {
  return (q >= 0 && q < h && w >= 0 && w < l); 
}

void bfs(int a, int b) {
  queue<pii> fila;
  fila.push(mp(a,b));
  marc[a][b] = 1;
  int cur = 0;
  int c = g[a][b];
  while(!fila.empty()) {
    cur++;
    int x = fila.front().first;
    int y = fila.front().second;
    for(int k = 0; k < 4; k++) {
      if(can(x + dx[k], y + dy[k])) {
	if((marc[x + dx[k]][y + dy[k]] == 0) && (c == g[x + dx[k]][y + dy[k]])) {
	  marc[x + dx[k]][y + dy[k]] = 1;
	  fila.push(mp(x + dx[k], y + dy[k]));
	}
      }
    }
    fila.pop();
  }
  resp = min(resp, cur);
}

int main() {
  resp = INF;
  scanf("%d%d", &h, &l);
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < l; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  
  for(int i  = 0; i < h; i++) {
    for(int j = 0; j < l; j++) {
      if(!marc[i][j]) bfs(i, j);
    }
  }
  printf("%d\n", resp);
}
