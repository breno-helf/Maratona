//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int M = 112;
const int N = 22;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int last;
int n, m;
string g[N];
int f[N], l[N];
int solve (int i, int j) {
    if (i == last) {
	if (j == 0) {
	    if (l[i] != -1)
		return l[i];
	    else return 0;
	} else {
	    if (f[i] != -1)
		return m + 1 - f[i];
	    else return 0;
	}
    } else {
	if (j == 0) {
	    if (l[i] != -1) {
		return min(2 * l[i] + 1 + solve (i + 1, 0), m + 2 + solve(i + 1, m + 1));
	    } else return solve (i + 1, 0) + 1;
	} else {
	    if (f[i] != -1)
		return min(2 * (m + 1 - f[i]) + 1 + solve(i + 1, m + 1), m + 2 + solve(i + 1, 0));
	    else return solve(i + 1, m + 1) + 1;
	}
    }
}

int main () {
    memset(f, -1, sizeof(f));
    memset(l, -1, sizeof(l));
    last = 0;
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--) {
	cin >> g[i];
	for (int j = 0; j < m + 2; j++) {
	    if (g[i][j] == '1') {
		if (f[i] == -1) f[i] = j;
		l[i] = j;
	    }
	}
	if (l[i] != -1)
	    last = max(last, i);
    }

    //    printf ("%d -- %d\n", solve (1, 0), solve(1, m + 1));
    
    cout << solve(0, 0) << '\n';
    
}

