#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 4123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, t, b[MAX], q;
int dp[MAX][MAX];
int calc[MAX];

int main () {
  for (scanf("%d", &q); q; q--) {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++)
      scanf("%d", &b[i]);

    memset(dp, 0, sizeof(dp));
    memset(calc, INF, sizeof(calc));
    dp[0][0] = 1;
    calc[0] = 0;
    set<int> v;
    v.insert(0);
    
    for (int j = 0; j <= 3600; j++) {
      set<int> p;
      for (int e : v) {
	for (int k = 0; k < n; k++) {
	  int g = max(0, e + b[k]);
	  g = min(3600, g);
	  dp[g][j + 1] = 1;
	  calc[g] = min(calc[g], j + 1);
	  if (calc[g] == (j + 1)) p.insert(g);
	}
      }
      v = p;
    }
    //debug("\n\n\n-----\n\n\n");
    int resp = t;
    while (calc[resp] == INF) resp++;
    printf("%d %d\n", calc[resp], resp - t);
  }
}
