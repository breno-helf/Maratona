//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int T1, T2, n;
int m[MAX];
int C[MAX][MAX][3];
int acc[MAX];
int dp[35][MAX][MAX];
int pai[35][MAX][MAX];

int solve(int i, int t1, int t2) {
    if (i == 0) {
	if (t1 == 0 && t2 == 0) return 0;
	else return INF + 1;
    }

    int &res = dp[i][t1][t2];
    if (res != INF) return res;

    for (int k = 0; k <= m[i]; k++) {
	if (t1 - k >= 0 && t2 - m[i] + k >= 0)
	    res = min(res, C[i][k][1] + C[i][m[i] - k][2] + solve(i - 1, t1 - k, t2 - m[i] + k));
    }
    return res;
}

int main() {
    while (true) {
	scanf("%d%d", &T1, &T2);
	if (T1 == 0 && T2 == 0) break;
	memset(dp, INF, sizeof(dp));
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	    scanf("%d", m + i);
	    acc[i] = acc[i - 1] + m[i];
	    
	    for (int j = 1; j <= m[i]; j++)
		scanf("%d", &C[i][j][1]);
	    
	    for (int j = 1; j <= m[i]; j++)
		scanf("%d", &C[i][j][2]);	    
	}
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
	    for (int t1 = 0; t1 <= T1; t1++) {
		for (int t2 = 0; t2 <= T2; t2++) {
		    for (int k = 0; k <= m[i]; k++) {
			if (t1 - k < 0 || t2 - m[i] + k < 0) continue;
			
			int &res = dp[i][t1][t2];
			int cur = C[i][k][1] + C[i][m[i] - k][2] + dp[i - 1][t1 - k][t2 - m[i] + k];
			if (cur < res) {
			    res = cur;
			    pai[i][t1][t2] = k;
			}
		    }
		}
	    }
	}

	vector<int> ANS;
	
	printf("%d\n", dp[n][T1][T2]);

	int a, b, c;
	a = n, b = T1, c = T2;
	
	while (a > 0) {
	    ANS.pb(pai[a][b][c]);
	    b -= ANS.back();
	    c -= m[a] - ANS.back();
	    a--;
	}

	reverse(ANS.begin(), ANS.end());

	for (int e : ANS)
	    printf("%d ", e);
	printf("\n\n");
	
    }
    return 0;
}

