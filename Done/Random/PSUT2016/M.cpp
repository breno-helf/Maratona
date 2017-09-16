//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 305;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;
const int K = MAX * MAX;

int n;
int dp[MAX][2 * MAX * MAX];
int v[MAX], sig[MAX];

int main() {
    scanf("%d", &n);
    scanf("%d", &v[0]);
    for (int i = 1; i < n; i++) {
	char c;
	scanf(" %c %d", &c, &v[i]);
	if (c == '-')
	    sig[i] = 1;
    }
    memset(dp, INF, sizeof(dp));

    dp[0][v[0] + K] = 0;
    
    int resp = INF;
   
    for (int i = 1; i < n; i++) {
	for (int j = 0; j < 2 * MAX * MAX; j++) {
	    if (sig[i]) {
		dp[i][j - v[i]] = min(dp[i][j - v[i]], dp[i - 1][j]);
		dp[i][j + v[i]] = min(dp[i][j + v[i]], dp[i - 1][j] + 1);
	    } else {
		dp[i][j - v[i]] = min(dp[i][j - v[i]], dp[i - 1][j] + 1);
		dp[i][j + v[i]] = min(dp[i][j + v[i]], dp[i - 1][j]);
	    }
	}
    }
    
    resp = dp[n - 1][K];

    if (resp >= INF) printf("-1\n");
    else printf("%d\n", resp);

    return 0;
}

