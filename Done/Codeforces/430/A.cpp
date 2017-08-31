//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll l, r, x, y, k;


int main() {
    scanf("%lld%lld%lld%lld%lld", &l, &r, &x, &y, &k);

    bool ok = false;
    
    for (ll a = l; a <= r; a++) {
	if (a % k == 0) {
	    if (a/k >= x && a/k <= y) ok = true;
	}
    }

    if (ok) puts("YES");
    else puts("NO");
}

