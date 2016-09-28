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

const int MAXM=1123;
const int MAXV=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int m, v, c[MAXM];
int dp[MAXM][MAXV];

int solve(int idx, int S) {
  if(S < 0) return 0;
  if(idx == m) {
    if(S == 0) return 1;
    else return 0;
  }
  int &res = dp[idx][S];
  if(res != -1) return res;
  else
    return res = max(solve(idx + 1, S), solve(idx + 1, S - c[idx]));
}

int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d", &v, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &c[i]);
  }
  if(solve(0,v)) puts("S");
  else puts("N");
  return 0;
}


