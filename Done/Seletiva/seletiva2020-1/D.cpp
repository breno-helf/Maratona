//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5 + 10;
const int ALPHA = 30;
const int INF = 0x3f3f3f3f;

int n, m, K;
int g[ALPHA][ALPHA];
char sChar[MAXN];
int s[MAXN];
int minCost[ALPHA][ALPHA];
int dp[MAXN][ALPHA];
int costSum[MAXN][ALPHA];

int main() {
   // Inicializando

   for (int u = 0; u < ALPHA; u++) {
      for (int v = 0; v < ALPHA; v++) {
         minCost[u][v] = INF;
      }
   }
   
   for (int i = 0; i < MAXN; i++) {
      for (int c = 0; c < ALPHA; c++) {
         dp[i][c] = INF;
         costSum[i][c] = 0;
      }
   }
      
   scanf(" %d%d%d", &n, &m, &K);
   scanf(" %s", sChar);
   for (int i = 1; i <= n; i++) {
      s[i] = sChar[i - 1] - 'a' + 1;
   }
   
   for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++) {
         scanf(" %d", &g[i][j]);
      }      
   }

   // Floyd Warshall Init
   for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= m; j++)
         minCost[i][j] = g[i][j];
      minCost[i][i] = 0;
   }

   // Floyd Warshall 
   for (int q = 1; q <= m; q++) {
      for (int i = 1; i <= m; i++) {
         for (int j = 1; j <= m; j++) {
            minCost[i][j] = min(minCost[i][j], minCost[i][q] + minCost[q][j]);
         }
      }
   }
   
   // Matriz acomulada dos custos de intervalo
   for (int c = 1; c <= m; c++)
      for (int i = 1; i <= n; i++)
         costSum[i][c] = costSum[i - 1][c] + minCost[s[i]][c];
   
   // DP
   dp[0][0] = 0;
   for (int i = 1; i <= n; i++) {
      for (int c = 1; c <= m; c++) {        
         for (int last = 0; last <= m; last++) {
            if (c == last) {
               dp[i][c] = min(dp[i][c], dp[i - 1][last] + minCost[s[i]][c]);
            }

            if (i >= K) {
               dp[i][c] = min(dp[i][c], dp[i - K][last] + costSum[i][c] - costSum[i - K][c]);
            }
         }
      }
   }
   int ans = INF;
   for (int c = 1; c <= m; c++)
      ans = min(ans, dp[n][c]);
   
   printf("%d\n", ans);
}
