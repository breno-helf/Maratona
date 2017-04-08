//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll dp[MAX][3];
char s[MAX];
int n;
map<char, int> a;

int main () {    
    scanf("%d", &n);
    scanf(" %s", s);
    for (int i = 0; i < 26; i++) {
	int v;
	scanf("%d", &v);
	a[i + 'a'] = v;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
	int lim = INF;
	dp[i][1] = INF;
	for (int j = i - 1; j >= 0; j--) {
	    lim = min(lim, a[s[j]]);
	    if (lim < i - j) break;
	    dp[i][0] = (dp[i][0] + dp[j][0]) % MOD;
	    dp[i][1] = min(dp[i][1], dp[j][1] + 1);
	    dp[i][2] = max(dp[i][2], max(dp[j][2], (ll)(i - j)));
	}
    }
    printf("%lld\n%lld\n%lld\n", dp[n][0], dp[n][2], dp[n][1]);
    return 0;
}

