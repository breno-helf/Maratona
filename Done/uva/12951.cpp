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

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, c, p[MAXN], dp[MAXN][2];

int solve(int idx, int buy) {
  if(idx == n) {
    if(buy == 1) return -INF;
    else return 0;
  }
  int &res = dp[idx][buy];
  if(res != -1) return res;
  if(buy == 1) {
    return res = max(solve(idx + 1, buy), solve(idx + 1, !buy) + p[idx]);
  }
  else {
    return res = max(solve(idx + 1, buy), solve(idx + 1, !buy) - p[idx] - c);
  }
}

int main() {
  while(cin >> n >> c) {
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << max(solve(0, 0), solve(0, 1) - p[0] - c) << '\n'; 
  }
  return 0;
}
