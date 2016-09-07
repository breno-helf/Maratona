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

bool dp[MAXN][MAXN][2];
vector<int> resp;
int n, p, m;

void solve(int v, int u) {
  for(int j = 0; j <= p; j++) {
    for(int k = 0; k <= j; k++) {
      dp[j][k][u] |= dp[j][k][!u];
      if(j - v >= 0) {
	dp[j][k][u] |= dp[j - v][k][!u];
	if(k - v >= 0) {
	  dp[j][k][u] |= dp[j - v][k - v][!u];
	}
      }
    }
  }
}

int main() {
  dp[0][0][0] = 1;  
  scanf("%d%d", &n, &p);
  int use = 0;
  for(int i = 0; i < n; i++) {
    scanf("%d", &m);
    use = !use;
    solve(m, use);
  }
      
  for(int i = 0; i <= p; i++) if(dp[p][i][0] || dp[p][i][1]) resp.pb(i);

  int tam = resp.size();
  printf("%d\n", tam);
  for(int i = 0; i < tam; i++) {
    printf("%d", resp[i]);
    if(i+1 == tam) putchar('\n');
    else putchar(' ');
  }
}
