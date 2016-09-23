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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n, c[MAXN], dp[MAXN][2];

ll solve(ll idx, ll peg) {
  if(idx == (n - 1)) return 0;
  ll &res = dp[idx][peg];
  if(res != -1) return res;
  else {
    if(peg == 1)
      return res = solve(idx + 1, 0); 
    else {
      return res = max(solve(idx + 1, 0), solve(idx + 1, 1) + c[idx + 1]);
    }
  }
}

int main() {
  ll tt;
  scanf("%lld", &tt);
  for(ll t = 1; t <= tt; t++) {
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++) scanf("%lld", &c[i]);
    printf("Case %lld: %lld\n", t, max(solve(0,0), c[0] + solve(0,1)));
  }
  return 0;
}

