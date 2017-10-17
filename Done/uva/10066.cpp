//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n1, n2;
int t1[MAX], t2[MAX];
int dp[MAX][MAX];
int pai[MAX][MAX];

int lcs(int i, int j) {
    if (i == 0 || j == 0) return 0;
    int &res = dp[i][j];
    if (res != -1) return res;
    
    if (t1[i] == t2[j]) res = max(res, lcs(i - 1, j - 1) + 1);
    res = max(res, max(lcs(i - 1, j), lcs(i, j - 1)));

    return res;
}

int main() {
    int t = 1;
    while (true) {
	scanf("%d%d", &n1, &n2);
	if (n1 == 0 && n2 == 0) break;

	memset(dp, -1, sizeof(dp));

	
	for (int i = 1; i <= n1; i++)
	    scanf("%d", t1 + i), dp[i][0] = 0;
	for (int i = 1; i <= n2; i++)
	    scanf("%d", t2 + i), dp[0][i] = 0;


	dp[0][0] = 0;
	
	for (int i = 1; i <= n1; i++) {
	    for (int j = 1; j <= n2; j++) {
		if (dp[i - 1][j] > dp[i][j]) {
		    dp[i][j] = dp[i - 1][j];
		    pai[i][j] = 1;
		}
		if (dp[i][j - 1] > dp[i][j]) {
		    dp[i][j] = dp[i][j - 1];
		    pai[i][j] = 2;
		}

		if (t1[i] == t2[j]) {
		    if (1 + dp[i - 1][j - 1] > dp[i][j]) {
			dp[i][j] = 1 + dp[i - 1][j - 1];
			pai[i][j] = 3;
		    }
		}
	    }
	}

	vector<int> LCS;
	int a = n1, b = n2;
	while (a != 0 && b != 0) {
	    if (pai[a][b] == 1) a--;
	    else if (pai[a][b] == 2) b--;
	    else {
		LCS.pb(t1[a]);
		a--;
		b--;
	    }
	}
	
	printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", t++, dp[n1][n2]);

	// reverse(LCS.begin(), LCS.end());
	// debug ("A LCS eh:\n");
	// for (auto e : LCS) {
	//     debug("%d ", e);
	// }
	// debug("\n\n");
    }
    return 0;
}


