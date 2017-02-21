//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int k, q;
vector<ld> resp;
static ld dp[MAX][2];

bool underflow(ld x) {
    return (x < 1e-18);
}

int main () {
    cin >> k >> q;
    int cur = 0;
    dp[0][cur ^ 1] = 1;
    int it = 10000;
    resp.pb(0);
    while(it--) {
	for (int i = 0; i <= k; i++)
	    dp[i][cur] = 0;
	
	for (int i = 0; i <= k; i++) {
	    ld p = (ld)i / (ld)k;
	    if(underflow(dp[i][cur ^ 1])) dp[i][cur ^ 1] = 0.0;
	    dp[i][cur] += dp[i][cur ^ 1] * p;
	    dp[i + 1][cur] += dp[i][cur ^ 1] * (1.0 - p);
	}
     
	resp.pb(dp[k][cur]);
	cur ^= 1;
    }
    sort(resp.begin(), resp.end());
    for (int i = 0; i < q; i++) {
	ld p;
	cin >> p;
	p = ((ld)p) / (ld)2e3;
	int day = lower_bound(resp.begin(), resp.end(), p) - resp.begin();
	cout << day << '\n';
    }
    return 0;
}


