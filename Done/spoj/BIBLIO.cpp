//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of SÃ£o Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;
 
#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
 
int dp[MAXN][MAXN], f[MAXN], acc[MAXN], n;
 
int solve(int l, int r) {
  if(l == r) return 0;
  else {
    int &res = dp[l][r];
    if(res != INF) return res;
    for(int i = l; i < r; i++)
      res = min(res, solve(l, i) + solve(i + 1, r) + f[i] + (i ? acc[i - 1] : 0) - (l ? acc[l - 1] : 0) + acc[r - 1] - acc[i]);
    return res;
  }
}
 
int main() {
  int t = 1;
  while(scanf("%d", &n) != EOF && n > 0) {
    if(t > 1) putchar('\n');
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i < n; i++) {
      scanf("%d", &f[i]);
      acc[i] = f[i] + (i ? acc[i-1] : 0);
    }
    int resp = INF;
    for(int i = 0; i < n; i++)
      resp = min(resp, solve(0, i) + solve(i + 1, n));
    
    printf("Teste %d\n%d\n", t++, resp);
  }
  return 0;
}
