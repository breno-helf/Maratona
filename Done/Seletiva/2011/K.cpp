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

int n, dp[MAXN][MAXN];

struct cx{
  int w;
  int r;
  int s;
}c[MAXN];

bool cmp(cx a, cx b) {
  if(a.s < b.s) return 0;
  return 1;
}

int solve(int i, int sz) {
  if(sz == 0) return INF;
  int &res = dp[i][sz];
  if(res != -1) return res;
  if(i == 0) {
    if(sz == 1) return c[i].r;
    else return -INF;
  }
  int ret = solve(i-1,sz);
  int flt = solve(i-1,sz-1);
  if(flt >= c[i].w) ret = max(ret, min(flt - c[i].w, c[i].r));
  return res = ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    int resp = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &c[i].w, &c[i].r);
      c[i].r -= c[i].w;
      c[i].s = c[i].w + c[i].r;
    }
    sort(c, c + n, cmp);
    for(int i = n; i > 0; i--) {
      if(solve(n-1, i) >= 0) {
	//debug("[-->] %d\n", solve(n-1, i));
	resp = i;
	break;
      }
    }
    printf("%d\n", resp);
  }
}
