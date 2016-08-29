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

const int MAXN=112;
const ll  INF= (ll)1e14;
const ll  MOD=1000000007;

int m, b[MAXN], t;
int n, k;
int c[MAXN], p[MAXN][MAXN];

ll dp[MAXN][MAXN][MAXN];

ll solve(int tam, int quero, int cor) {
  debug("%d %d %d\n", tam, quero, cor);

  if(n == tam) {
    if(quero == 0) 
      return 0;
    else
      return INF;
  }

  if(dp[tam][quero][cor] != -1) return dp[tam][quero][cor];
  
  if(c[tam] != 0) {
    if(c[tam] == cor) {
      return dp[tam][quero][cor] = solve(tam + 1, quero, cor);
    }
    else {
      return dp[tam][quero][cor] = solve(tam + 1, quero - 1, c[tam]);
    }
  }
  if(c[tam] == 0) {
    ll ret = INF;
    /*    if(quero == 0) {
      return dp[tam][quero][cor] = solve(tam + 1, quero, cor) + p[tam][cor];
      } */
    if(true) {
      for(int i = 1; i <= m; i++) {
	if(i == cor) {
	  debug("%d\n", p[tam][cor]);
	  ret = min(ret, solve(tam+1, quero, cor) + p[tam][cor]);
	}
	else {
	  debug("%d\n", p[tam][i]);
	  ret = min(ret, solve(tam+1, quero - 1, i) + p[tam][i]);
	}
      }
      return dp[tam][quero][cor] = ret;
    }
  }
  //  return dp[tam][quero][cor] = INF;
}


int main() {
  memset(dp, -1, sizeof(dp));
   
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }

  //debug("%d\n", t);
  
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &p[i][j]);
     }
  }
  /*
  if(t > k) {
    puts("-1");
    return 0;
  }
  */
  ll resp = solve(0, k, 0);
  if (resp == INF) puts("-1");
  else printf("%I64d\n", resp);

  return 0;
}
    
