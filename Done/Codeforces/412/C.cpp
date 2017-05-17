//If you are trying to hack me I wish you can get it, Good Luck :D. I am such a noob
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 4;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll T, X, Y, P, Q;

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int cmp (ll a, ll b, ll c, ll d) {
    if (a * d > c * b) {
	return 1;
    } else if (a * d < c * b) {
	return -1;
    }
    return 0;
}

int main () {
    cin >> T;
    for (int t = 0; t < T; t++) {
	cin >> X >> Y >> P >> Q;
	
	if ((P == 1 && Q == 1) || P == 0) {
	    if (cmp(X, Y, P, Q) == 0) {
		cout << 0 << '\n';
		continue;
	    } else {
		cout << -1 << '\n';
		continue;
	    }
	}

	
	if (cmp(X, Y, P, Q) == 0) {
	    cout << 0 << '\n';
	    continue;
	} else {
	    ll l = max(1LL, (Q + Y - 1) / Q), r = 1e9;
	    //l = max(l, (P + X - 1 / P));
	    while (l < r) {
		ll mid = (l + r) / 2; 
		ll q = Q * mid;
		ll p = P * mid;
		if ((X + (q - Y)) >= p && X <= p) r = mid;
		else l = mid + 1;
	    }
	    if ((X + (Q * l - Y)) >= P * l && X <= P * l)
		cout << Q * l - Y << '\n';
	    else
		cout << -1 << '\n';
	    continue;
	}	
    }
    return 0;
}
