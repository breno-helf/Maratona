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

int n, a[MAXN];
ll cnt[MAXN];
ll dp[MAXN];

ll solve(int num) {
  if(num > 100000) return 0;
  else {
    ll &res = dp[num];
    if(res != -1) return res;
    if(cnt == 0) return res = solve(num + 1);
    else {
      return res = max(solve(num + 2) + cnt[num], solve(num + 1));
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    cnt[a[i]] += a[i];
  }
  memset(dp, -1, sizeof(dp));
  printf("%lld\n", solve(0));
}
  
