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
const ll  INF = (ll)(1e15);
const ll  MOD = 1000000007;

int n, d;
ll p[MAX];
ll dp[MAX][MAX][22];
ll acc[MAX];
ll donda (ll k) {
    if (k % 10 < 5) return (k - k % 10);
    else return (k + 10 - k % 10);
}

ll solve (int i, int s, int r) {
    ll &res = dp[i][s][r];

    if (res != -1) return res;
    
    if (i == n) {
	return res = donda(acc[n] - acc[s - 1]);
    } else {
	if (r > 0)
	    return res = min(solve(i + 1, s, r), solve(i + 1, i + 1, r - 1) + donda(acc[i] - acc[s - 1]));
	else
	    return res = solve(i + 1, s, r);
    }
}


int main () {
    memset(dp, -1, sizeof(dp));
    
    scanf ("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) {
	scanf ("%lld", p + i);
	acc[i] = acc[i - 1];
	acc[i] += p[i];
    }

    printf ("%lld\n", solve(1, 1, d));
}
