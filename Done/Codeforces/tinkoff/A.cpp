//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k;

ll a[MAX];

int main () {
    scanf ("%lld%lld", &n, &k);
    for (int i = 0; i < n; i++)
	scanf ("%lld", a + i);
    sort(a, a + n);
    ll resp = 0;
    for (int i = 1; i < n; i++) {
	if ((a[i] - a[0]) % k != 0) {
	    resp = -1;
	    break;
	} else {
	    resp += (a[i] - a[0]) / k;
	}	
    }
    printf ("%lld\n", resp);
}

