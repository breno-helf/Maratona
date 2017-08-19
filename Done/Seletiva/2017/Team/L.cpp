//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e6 + 10;
const int MAXM = 1e2 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int dp[MAXM][MAXN];
int n, m, k;
char s[MAXN], p[MAXM];

int solve(int j, int i) {
    int &res = dp[j][i];

    if (j == m) return res = 0;
    if (i == n) return res = INF;

    if (res != -1) return res;

    res = INF;
    
    if (p[j] == s[i]) res = min(res, solve(j + 1, i + 1));
    res = min(res, solve(j + 1, i) + 1);
    res = min(res, solve(j, i + 1) + 1);
    res = min(res, solve(j + 1, i + 1) + 1);
    return res;
}

int main() {    
    scanf("%d%d%d", &m, &n, &k);
    scanf(" %s %s", p, s);
    int resp = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) dp[i][0] = INF;
    for (int j = 1; j <= n; j++) dp[0][j] = 0;
    
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
	    dp[i][j] = INF;
	    if(s[j - 1] == p[i - 1])
		dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
	    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
	    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
	    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
    	}
    }
    
    for (int i = 1; i <= n; i++) resp = min(resp, dp[m][i]);
    
    printf("%s\n", (resp <= k ? "S" : "N"));
}

