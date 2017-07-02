//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1231;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll a, b;

ll fac (ll x) {
    ll ret = 1;
    for (ll i = 1; i <= x; i++) {
	ret *= i;
    }
    return ret;
}

int main () {
    cin >> a >> b;
    cout << fac(min(a, b)) << '\n';
}


