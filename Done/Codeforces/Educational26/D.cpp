#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 200 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
ll a[MAX];

int two[MAX], fiv[MAX];

pii dp[MAX][MAX];

int main() {
    for (int i = 0; i < MAX; i++)
	for (int j = 0; j < MAX; j++)
	    dp[i][j] = pii(-1, -1);
    
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
	scanf("%lld", a + i);
	ll num = a[i];
	while(num % 2 == 0) {
	    two[i]++;
	    num /= 2;
	}

	while(num % 5 == 0) {
	    fiv[i]++;
	    num /= 5;
	}
    }

    dp[0][0] = pii(0, 0);

    for (int i = 1; i <= n; i++) {
	for (int j = 0; j <= k; j++) {
	    pii op1 = dp[i - 1][j];
	    pii op2 = pii(-INF, -INF);

	    if(j > 0) op2 = dp[i - 1][j - 1];
	    op2 = pii(op2.first + two[i], op2.second + fiv[i]);
	    int v1 = min(op1.first, op1.second);
	    int v2 = min(op2.first, op2.second);

	    if (v1 > v2) dp[i][j] = op1;
	    else dp[i][j] = op2;
	}
    }
    
    
    printf("%d\n", max(0, min(dp[n][k].first, dp[n][k].second)));
    return 0;
}

