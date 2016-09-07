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

int solve(int tam, int comprei, int val) {
  if(tam == n) {
    if(comprei == 1) return -INF;
    else return 0;
  }
  int &res = dp[tam][comprei];
  if(res != -1) return res;
  
  if(comprei == 0)
    return res = max(solve(tam+1, 1, p[tam]) - c - p[tam], solve(tam+1, 0, 0));
  else
    return res = max(solve(tam+1, 0, 0) + p[tam], solve(tam+1, 1, val));
}


int main() {
  while(scanf("%d%d", &n, &c) != EOF) {
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
    }
    printf("%d\n", solve(0,0,0));
  }
  return 0;
}
