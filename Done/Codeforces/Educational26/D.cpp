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

int dp[MAX][MAX * 50];

int main() {
    memset(dp, -INF, sizeof(dp));
    
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

    dp[0][0] = 0;
    int resp = 0;
    for (int i = 1; i <= n; i++) {
	for (int j = k - 1; j >= 0; j--) {
	    for (int t = 0; t <= j * 30; t++) {
		dp[j + 1][t + fiv[i]] = max(dp[j + 1][t + fiv[i]], dp[j][t] + two[i]);
	    }
	}
    }

    for (int t = 0; t < 50 * MAX; t++) resp = max(resp, min(dp[k][t], t));
    
    printf("%d\n", resp);
    return 0;
}

