#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN = 212345;
const int INF = 0x3f3f3f3f;

int dp[MAXN];
int n;

vector<int> m;

int solve(int a) {
  if(a == 0) return 0;
  int &res = dp[a];
  if(res != -1) return res;
  int ret = INF;
  for(int i : m)
    if((a - i) >= 0) ret = min(ret, solve(a - i) + 1);
  return res = ret;
}

int main() {
  int aux = 1;
  for(int i = 1; aux <= 100000; i++) {
    aux *= i;
    m.pb(aux);
  }
  memset(dp, -1, sizeof(dp));
  
  while(scanf("%d", &n) != EOF) {
    printf("%d\n", solve(n));
  }

  return 0;
}
