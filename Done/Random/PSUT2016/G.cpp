//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll m;
ll k;

ll v[MAX], sum, med;
ll a[MAX];

bool ok(ll x) {
    ll p = upper_bound(v + 1, v + m + 1, x) - v;
    
    ll L = x * (ll)(p - 1) - a[p - 1];
    ll R = (a[m] - a[p - 1]) - x * (ll)(m - p + 1);
    
    return (L >= R && R <= k);
}

int main() {
    a[0] = 0;
    scanf("%lld %lld", &m, &k);

    for (int i = 1; i <= m; i++) {
	scanf("%lld", v + i);
	sum += v[i];
	
    }

    sort(v + 1, v + m + 1);

    for (int i = 1; i <= m; i++)
	a[i] = a[i - 1] + v[i];

    
    med = (sum + m - 1) / m;

    ll resp;
    ll L = med, R = v[m];

    while (L < R) {
	
	ll M = (L + R) / 2;
	if (ok(M)) R = M;
	else L = M + 1;
    }
    resp = R;
    
    printf("%lld\n", resp);
    
    return 0;
}

