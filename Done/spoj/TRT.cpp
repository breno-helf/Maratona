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

int n, v[MAXN];
int dp[MAXN][MAXN];

ll solve(int l, int r, int a) {
  if(dp[l][r] != -1)
    return dp[l][r];
  else if(l == r)
    return a*v[l];
  else
    return dp[l][r] = max(v[l]*a + solve(l + 1, r, a + 1), v[r]*a + solve(l, r - 1, a + 1));

}

int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for(int i = 1; i <= n; i++)
    scanf("%d", v + i);
  printf("%lld\n", solve(1, n, 1));
  return 0;
}

