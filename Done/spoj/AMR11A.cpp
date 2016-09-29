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

const int MAXN=512;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int s[MAXN][MAXN];
int dp[MAXN][MAXN];
int r, c, t, init;

bool can(int k) {
  s[0][0] = init + k;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(i == 0 || j == 0) {
	if(i == 0 && j == 0)
	  dp[i][j] = s[i][j];
	else if(i == 0)
	  dp[i][j] = s[i][j] + dp[i][j - 1];
	else
	  dp[i][j] = s[i][j] + dp[i - 1][j];
      }
      else {
	dp[i][j] = s[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
      }
      if(dp[i][j] <= 0) dp[i][j] = -INF;
    }
  }
  if(dp[r - 1][c - 1] > 0) return 1;
  else return 0;
}


int main() {
  for(scanf("%d", &t); t; t--) {
    scanf("%d%d", &r, &c);
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
	scanf("%d", &s[i][j]);

    init = s[0][0];
    int lo = 0, hi = 300000000;
    while(lo < hi) {
      int mi = (lo + hi)/2;
      if(can(mi)) hi = mi;
      else lo = mi + 1;
    }
    printf("%d\n", lo);
  }
  return 0;
}
