//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1221;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll mmc(ll a, ll b) {
    return (a * b) / (__gcd(a, b));
}

ll breno(ll n, ll k) {
    int p = 1;
    for (int i = 0; i < k; i++) p *= 10;
    return mmc(n, p);
}

ll alex_bucevschi(ll n, ll k) {
    if (k == 0) return n;
    ll sol = 1e19;

    for (ll i = 1; i <= 9; i++) {
	ll x = n * i;
	ll y = x;
	ll cnt = 0;

	while (y % 10 == 0 && y) {
	    y /= 10;
	    cnt++;
	}

	for (; cnt < k; cnt++) x *= 10;
	
	sol = min(sol, x);
    }

    return sol;
}

ll nowchen(ll n, ll k) {
    ll m = n;
    ll two = 0;
    ll five = 0;
    ll ten = 0;

    while(n % 10 == 0) n = n / 10, ten++;
    while(n % 5 == 0) n = n / 5, five++;
    while(n % 2 == 0) n = n / 2, two++;

    ll now = 1;

    for (ten; ten < k; ten++) {
	if (five > 0) now = now * 2, five--;
	else
	if (two > 0) now = now * 5, two--;
	else now = now * 10;
    }

    return now * m;
}

ll ATAMHB(ll n, ll k) {
    ll z = n;
    ll i = 0, j = 0, e, s, ans, now;
    while(z != 1) {
	if (z % 5 == 0) {
	    i++;
	    z /= 5;
	} else break;		
    }
    z = n;
    while(z != 1) {
	if (z % 2 == 0) {
	    j++;
	    z /= 2;
	} else break;
    }

    z = pow(2, j) * pow(5, i);
    now = pow(10, k);
    
    if (z % now == 0) {
	return n;
    } else {
	if (j >= k) e = 0;
	else e = k - j;
	if (i >= k) s = 0;
	else s = k - i;

	ans = n * pow(2, e) * pow(5, s);
    }

    return ans;
}

inline int dig(ll n) {
    int sum = 0;
    while(n % 10 == 0) n /= 10, ++sum;
    return sum;
}

ll myworld(ll n, ll k) {
    if (dig(n) >= k) return n;

    ll mod = 1;
    while(k--) mod *= 10;

    for (ll i = 1; ; i++) {
	if (n * i % mod == 0) return n * i;
    }
}

ll ZZZZone(ll n, ll k) {
    ll ans = 1LL << 60;
    for (ll i = 1LL; i <= 1e6; i++) {
	ll x = n * i;

	int cnt = 0, cnt2 = 0;

	ll temp = x;

	while (temp % 10 == 0) { cnt++; cnt2++; temp = temp / 10LL; }
	while (temp != 0) { cnt2++, temp = temp / 10LL; }

	if (cnt2 + k > 18) continue;

	for (int j = 1; j <= k - cnt; j++) x = x * 10LL;
	ans = min(ans, x);
	
    }

    return ans;
}

int main() {
    srand(time(NULL));
    
    vector<pll> examples;
    examples.pb(pll(375, 4));
    examples.pb(pll(10000, 1));
    examples.pb(pll(38101, 0));
    examples.pb(pll(123456789, 8));

    vector<ll> ans;

    ans.pb(30000);
    ans.pb(10000);
    ans.pb(38101);
    ans.pb(12345678900000000);

    ll (*hacked)(ll, ll);
    hacked = ZZZZone;
    
    for (int i = 0; i < 4; i++) {
	pll E = examples[i];
	ll A = ans[i];
	ll brelf, romeno;
	ll n, k;
	n = E.first;
	k = E.second;
	brelf = breno(n, k);
	romeno = hacked(n, k);
	assert(brelf == A);
	if (brelf != romeno) {
	    printf("==> EXEMPLO BUGOU\n");
	    printf("%lld %lld\n", n, k);
	    printf("--> %lld %lld\n", brelf, romeno);
	    exit(0);
	}	
    }

    printf("Passou nos exemplos!\n");
    
    while (true) {
	ll brelf, romeno;
	ll n, k;
	n = rand() % ((ll)1e9) + 1;
	k = rand() % 9;
	brelf = breno(n, k);
	romeno = hacked(n, k);
	if (brelf != romeno) {
	    printf("%lld %lld\n", n, k);
	    printf("--> %lld %lld\n", brelf, romeno);
	    break;
	}
    }
    return 0;
}
