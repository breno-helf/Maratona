//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll dp[MAX];
ll num[MAX];

ll f (ll x) {
    if (dp[x] != 0) return dp[x];

    if (num[x] == 0) return dp[x] = ((x * (x - 1)) / 2) % MOD;

    else return dp[x] = ((x / num[x]) * f(num[x]) + f(x / num[x])) % MOD;
}

ll r, l, t;

int main () {
    scanf ("%lld %lld %lld", &t, &l, &r);

    for (ll i = 2; i * i < MAX; i++) {
	if (num[i] == 0) {
	    for (ll k = i * i; k < MAX; k += i) {
		if (num[k] == 0) num[k] = i;
	    }
	}
    }
    
    ll resp = 0;
    ll pow = 1;
    for (ll i = l; i <= r; i++) {
	//printf ("-- %lld %lld\n", pow, f(i));
	resp += (pow * f (i)) % MOD;
	resp %= MOD;
	pow *= t;
	pow %= MOD;
    }

    printf ("%lld\n", resp);
}

