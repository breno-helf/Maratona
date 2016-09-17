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

int n, m, f[2][MAXN][2], mx[2][MAXN], mx0, mx1, r0, r1;

void dfs(int u, int k) {
  if(f[k][u][0]) {
    dfs(f[k][u][0], k);
    mx[k][u] = mx[k][f[k][u][0]] + 1;
  }
  else mx[k][u] = 1;
  if(f[k][u][1]) dfs(f[k][u][1], k);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    f[0][a][0] = c;
    f[0][a][1] = b;
  }
  dfs(1, 0);
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    f[1][a][0] = b;
    f[1][a][1] = c;
  }
  dfs(1, 1);
  r0 = mx[0][1];
  r1 = mx[1][1];
  mx0 = mx1 = 1;
  for(int i = 1; i <= n; i++) mx0 = max(mx0, mx[0][i]);
  for(int i = 1; i <= m; i++) mx1 = max(mx1, mx[1][i]);

  //debug("--> %d %d %d %d\n", mx0, r0, mx1, r1);
  printf("%d\n", n + m - max(min(mx1,r0), min(mx0, r1)));
  return 0;
}
