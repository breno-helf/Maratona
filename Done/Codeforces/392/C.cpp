//This code was written by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, m, x, y;
ll resp[MAX][MAX], walk;
ll k;

void solve () {
    walk = k / ((2 * n - 2) * m);
    k %= ((2 * n - 2) * m);

    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++) {
	    if (i == 1 || i == n)
		resp[i][j] = walk;
	    else
		resp[i][j] = 2 * walk;
	}
    
    for (int i = 1; i <= n && k; i++)
	for (int j = 1; j <= m && k; j++) {
	    resp[i][j]++;
	    --k;
	}

    for (int i = n - 1; i >= 2 && k; i--)
	for (int j = 1; j <= m && k; j++) {
	    resp[i][j]++;
	    --k;
	}
}

int main () {
    cin >> n >> m >> k >> x >> y;
    if (n == 1) {
	cout << (k + m - 1)/m << ' ' << k/m << ' ';
	ll pos = k % m;
	if (pos == 0) pos = m;
	ll last = (pos >= y) ? ((k + m - 1)/m) : (k/m);
	cout << last << '\n';
    } else {
	solve();
	ll mx = 0, mn = (ll)1e18 + 1;
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= m; j++) {
		mn = min(mn, resp[i][j]);
		mx = max(mx, resp[i][j]);
	    }
	cout << mx << ' ' << mn << ' ';
	cout << resp[x][y] << '\n';
    }
    return 0;
}

