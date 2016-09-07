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

int n, m, c[MAXN];

vector<int> adj[MAXN];

vector<int> red, blue;

int dfs(int u) {
  int ret = 1;
  for(auto v : adj[u]) {
    if(!c[v]) {
      c[v] = (c[u] == 1) ? 2 : 1;

      if(c[v] == 1) red.pb(v);
      else blue.pb(v);
      
      if(ret) ret = dfs(v);
    }
    else if(c[u] == c[v]) return 0;
  }
  return ret;
}


int main() {
  int resp = 1;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  for(int i = 1; i <= n; i++) {
    if(!c[i]) {
      red.pb(i);
      c[i] = 1;
      int done = dfs(i);
      if(!done) {
	resp = 0;
	break;
      }
    }
  }
  if(!resp) puts("-1");
  else {
    int tam = red.size();
    printf("%d\n", tam);
    for(int i = 0; i < tam; i++) {
      printf("%d", red[i]);
      if(i+1 == tam) putchar('\n');
      else putchar(' ');
    }
    tam = blue.size();
    printf("%d\n", tam);
    for(int i = 0; i < tam; i++) {
      printf("%d", blue[i]);
      if(i+1 == tam) putchar('\n');
      else putchar(' ');
    }
  }
}
  

