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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


ll b, g, dp[MAXN][MAXN];

ll solve(int idx, int dance) {
  if(idx == b) {
    if(dance != 0) return 0;
    else return 1;
  }
  else {
    ll &res = dp[idx][dance];
    if(res != -1) return res;
    else {
      res = ((dance)*solve(idx + 1, dance - 1))%MOD + ((g - dance)*solve(idx + 1, dance))%MOD;
      res %= MOD;
      return res;
    }
  }
}

int main() {
  while(1) {
    scanf("%lld%lld", &b, &g);
    if(b == 0 && g == 0) break;
    for(int i = 0; i <= b; i++)
      for(int k = 0; k <= g; k++)
	dp[i][k] = -1;
    
    if(b < g) { 
      putchar('0');
      putchar('\n');
    }
    
    else if(g == 1) {
      putchar('1');
      putchar('\n');
    }
    
    else {
      ll prin = solve(0, g);
      printf("%lld\n", prin);
    }
      
  }
  return 0;
}

