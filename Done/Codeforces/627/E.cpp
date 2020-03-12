//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, h, l, r;
int a[MAX];
int DP[MAX][MAX];

int main() {
   memset(DP, -1, sizeof(DP));
   
   scanf("%d %d %d %d", &n, &h, &l, &r);

   for (int i = 1; i <= n; i++)
      scanf("%d", a + i);

   DP[0][0] = 0;
   int ans = 0;
   for (int i = 1; i <= n; i++) {
      for (int t = 0; t < h; t++) {
         int last1 = (t - a[i] + h) % h;
         int last2 = (t - a[i] + 1 + h) % h;
         int op1 = -1, op2 = -1;
         
         if (DP[i - 1][last1] != -1)
            op1 = DP[i - 1][last1] + (t >= l && t <= r);
         
         if (DP[i - 1][last2] != -1)
            op2 = DP[i - 1][last2] + (t >= l && t <= r);

         DP[i][t] = max(op1, op2);

         if (i == n)
            ans = max(ans, DP[i][t]);
      }
   }

   printf("%d\n", ans);
}
