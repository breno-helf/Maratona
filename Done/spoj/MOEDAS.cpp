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

const int MAXN=112;
const int MAXM=51234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int m, n, c[MAXN], dp[MAXN][MAXM];

int solve(int idx, int val) {
  if(val < 0) return INF;
  if(idx == n) {
    if(val == 0) return 0;
    else return INF;
  }
  int &res = dp[idx][val];
  if(res != -1) return res;
  else
    return res = min(solve(idx + 1, val), 1 + solve(idx, val - c[idx]));
}


int main() {
  while(cin >> m >> n) {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      cin >> c[i];
    }
    int resp = solve(0, m);
    if(resp == INF) puts("Impossivel");
    else printf("%d\n", resp);
  }
  return 0;
}
