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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, v[MAXN], p[MAXN], num[MAXN];
int resp[MAXN], l[MAXN];
vector<int> q[MAXN];
vector<int> val[MAXN];
vector<int> g;
vector<int> c[MAXN];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++) scanf("%d", &v[i]);
  for(int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i], &num[i]);
    c[p[i]].pb(i);
    val[p[i]].pb(0);
    if(c[p[i]].size() == 1) g.pb(p[i]);
    l[i] = 0;
    for(int k = 1; k <= num[i]; k++){
      int a;
      scanf("%d", &a);
      q[i].pb(a);
    }
  }
  sort(g.begin(), g.end());
  int tam = g.size();
  int f = 0;
  for(int i = tam-1; i >= 0;) {
    int tm = c[g[i]].size();
    for(int k = 0; k < tm; k++) {
      if(val[g[i]][k]) continue;
      int a = c[g[i]][k];
      int w = q[a][l[a]];
      if(l[a] < num[a]) {
	while(v[w] == 0) {
	  l[a]++;
	  if(l[a] == num[a]) break;
	  w = q[a][l[a]];
	}
      }
      if(l[a] == num[a]) {
	resp[a] = -1;
	val[g[i]][k] = 1;
	f++;
      }
    }

    if(f < tm) {
      int at = INF, pr = INF, id = -1;
      for(int k = 0; k < tm; k++) {
	if(val[g[i]][k]) continue;
	int a = c[g[i]][k];
	if(l[a] < pr) {
	  at = a;
	  pr = l[a];
	  id = k;
	}
	else if(l[a] == pr && a < at) {
	  at = a;
	  pr = l[a];
	  id = k;
	}
      }
      val[g[i]][id] = 1;
      f++;
      int w = q[at][l[at]];
      resp[at] = w;
      v[w]--;
    }
    else {
      f = 0;
      i--;
      continue;
    }
  }
  for(int i = 1; i <= n; i++) {
    printf("%d\n", resp[i]);
  }

}
