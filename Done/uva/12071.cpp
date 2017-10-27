//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1005;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int N, K;
ll dp[MAX][5 * MAX];
ll L[5 * MAX];

ll solve(int k, int n) {
    ll &res = dp[k][n];
    if (res != -1) return res;

    if (3 * k > n) return res = INF;
    if (k == 0) return res = 0;

    return res = min(solve(k - 1, n - 2) + (L[n] - L[n - 1]) * (L[n] - L[n - 1]), solve(k, n - 1));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &K, &N);
	K += 8;
	for (int i = 1; i <= N; i++) {
	    scanf("%lld", L + i);	    
	}
	sort(L + 1, L + 1 + N);
	reverse(L + 1, L + 1 + N);
	
	printf("%lld\n", solve(K, N));
    }

    return 0;
}

