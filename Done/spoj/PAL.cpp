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

const int MAXN=2123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, dp[MAXN];
ll nor[MAXN][MAXN], inv[MAXN][MAXN];
int p = 29;
ll pr[MAXN];
char s[MAXN];

int cnt = 0;
/*
int solve(int ini, int fim) {
  cnt++;
  int &res = dp[ini][fim];
  if(res != -1) return res;
  ll a = nor[ini][fim - 1];
  ll rev = inv[fim - 1][ini];
  if(fim == n) {
    if(a == rev) return res = 1;
    else return INF;
  }
  else {
    if(a == rev) return res = min(1 + solve(fim, fim + 1), solve(ini, fim + 1));
    else return res = solve(ini, fim + 1);
  }
}
*/
int main() {
  int t = 1;
  pr[0] = 1;
  for(int i = 1; i <= 2010; i++) {
    pr[i] = p*pr[i - 1];
    pr[i] %= MOD;
  }
  while(1) {
    scanf("%d", &n);
    if(n == 0) break;
    scanf(" %s", s);
    for(int i = 0; i <= n; i++) {
      for(int k = 0; k <= n; k++) {
	nor[i][k] = inv[i][k] = 0;
	dp[i] = 0;
      }
    }
    for(int i = 0; i < n; i++) {
      for(int k = i; k < n; k++) {
	if(k > i) nor[i][k] = nor[i][k-1] + (s[k] - 'a')*pr[k - i];
	else nor[i][k] = (s[k] - 'a')*pr[k - i];
	nor[i][k] %= MOD;
      }
    }
    for(int i = (n-1); i >= 0; i--) {
      for(int k = i; k >= 0; k--) {
	if(k < i) inv[i][k] = inv[i][k + 1] + (s[k] - 'a')*pr[i - k];
	else inv[i][k] = (s[k] - 'a')*pr[i - k];
	inv[i][k] %= MOD;
      }
    }

    if(t > 1) putchar('\n');
    int resp;
    for(int i = 0; i < n; i++) {
      if(nor[0][i] == inv[i][0]) dp[i] = 1;
      else {
	int m = INF;
	for(int j = 1; j <= i; j++) {
	  if((nor[j][i] == inv[i][j]) && ((dp[j - 1] + 1) < m))
	    m = dp[j - 1] + 1;
	}
	dp[i] = m;
      }
    }
    resp = dp[n - 1];
    printf("Teste %d\n%d\n", t++, resp);
    //debug("%d %d %d\n", cnt, c1, c2);
  }
  return 0;
}
