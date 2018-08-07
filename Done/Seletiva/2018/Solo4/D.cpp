//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 505;

double dp[MAX][MAX][MAX], p;
int n;


int main() {
    while (scanf("%d %lf", &n, &p)) {
        if (n == 0) break;
        dp[0][0][0] = 1;

        double ans = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k <= i; k++) {
                dp[i][0][k] = 0;
                for (int j = 1; j <= k; j++) {
                    if (j != k) dp[i][j][k] = dp[i - 1][j - 1][k] * p;
                    if (j == k) dp[i][j][k] = dp[i - 1][j - 1][k - 1] * p + dp[i - 1][j - 1][k] * p;
                    dp[i][0][k] += dp[i - 1][j][k] * (1 - p);

                    if (i == n) ans += k * dp[i][j][k];
                }
                dp[i][0][k] += dp[i - 1][0][k] * (1 - p);
                if (i == n) ans += k * dp[i][0][k];
            }            
        }

        printf("%.6lf\n", ans);
    }

    return 0;
}
