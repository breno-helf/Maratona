//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, s, t;
int k[MAX];
ll resp[MAX];
multiset<int> bags;
map<int, ll> val;

ll solve (int b) {
    int pos = b;
    bags.erase(bags.find(pos));
    pos = (pos + t) % s;
    ll cost = t;
    if (bags.empty()) return cost;

    auto it = bags.lower_bound(pos);

    if (it == bags.end()) {
	cost += s - pos;
	pos = 0;
	it = bags.lower_bound(0);
    }

    cost += *it - pos;
    return cost + solve(*it);
}

ll gcd (ll a, ll b) {
    if (b == 0LL) return a;
    return gcd(b, a % b);
}

int main () {
    scanf ("%d %d %d", &n, &s, &t);

    for (int i = 0; i < n; i++) {
	scanf ("%d", k + i);
    }

    sort (k, k + n);
    
    for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	    bags.insert(k[j]);
	}
	resp[i] = solve (k[i]);
	val[k[i]] = resp[i];
	debug ("%lld\n", resp[i]);
    }
    
    for (int j = 0; j < n; j++) {
	bags.insert(k[j]);
    }
    
    ll tot = 0;
    ll mx = -(ll)1e17;
    ll mn = (ll)1e17;
    
    for (int i = 0; i < s; i++) {
        ll dist;
	ll Dnxt;
	ll pos;

	auto it = bags.lower_bound(i);
	
	if (it == bags.end()) {
	    it = bags.lower_bound(0);
	}

	pos = *it;
	
	Dnxt = (pos - i + s) % s;
	
	dist = val[pos] + Dnxt;

	debug ("%d --> %lld === %d (%lld %lld) \n", i, dist, nxt, resp[nxt], Dnxt);

		
	mx = max(mx, dist);
	mn = min(mn, dist);

	
	tot += dist;
	
    }
    ll S = s;
    ll D = gcd (tot, S);
    tot /= D;
    S /= D;

    printf ("%lld\n", mn);
    printf ("%lld\n", mx);
    printf ("%lld/%lld\n", tot, S);

    return 0;
}



