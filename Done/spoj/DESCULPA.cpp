#include<bits/stdc++.h>
using namespace std;

const int MAXC = 1e3 + 10;
const int MAXF = 55;
const int INF = 0x3f3f3f3f;

int dp[MAXF][MAXC];
int C, F;
int N[MAXF], D[MAXF];

int solve(int f, int c) {
   if (c < 0) return -INF;
   if (f == F) return 0;
   
   int &res = dp[f][c];
   if (res != -INF) return res;
   
   return res = max(solve(f + 1, c), solve(f + 1, c - N[f]) + D[f]);
}

int main() {
   int T = 1;
   while (true) {
      scanf("%d%d", &C, &F);
      if (C == 0 && F == 0) break;
      for (int i = 0; i < MAXF; i++)
         for (int j = 0; j < MAXC; j++)
            dp[i][j] = -INF;
      for (int i = 0; i < F; i++)
         scanf("%d%d", &N[i], &D[i]);
      printf("Teste %d\n%d\n\n", T++, solve(0, C));
   }

   return 0;
}
