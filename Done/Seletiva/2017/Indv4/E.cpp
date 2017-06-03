//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n;
pii P[MAX];
ll d;

ll calc (ll a, ll b) {    
    ll A = (a + b) / 2;
    ll B = (b - a) / 2;
    
    ll ret = 0;
    for (ll i = 0; i < n; i++) {
	ret += (ll)(abs(A - P[i].first));
	ret += (ll)(abs(B - P[i].second));
    }
    return ret;
}

ll ternary (ll L, ll R, ll fix, ll type) {
    vector<int> test;
    ll lo = L, hi = R;

    if (lo % 2 != fix % 2) {
	lo++;
    }

    if (hi % 2 != fix % 2)
	hi--;
    
    ll k = 0;
    while (k < 60 && lo < hi) {
	ll mid = (lo + hi) / 2;

	if (type <= 1) {
	    if (calc (mid, fix) > calc (mid + 2, fix)) {
		lo = mid;
	    } else hi = mid;
	} else {
	    if (calc (fix, mid) > calc (fix, mid + 2)) {
		lo = mid;
	    } else hi = mid;
	}
	
	k++;
    }

    
    
    for (ll i = -1; i <= 1; i++) {
	test.pb(lo + i);
	test.pb(hi + i);
    }

    ll ret = 1e17;
    
    for (ll e : test) {
	if ((e + fix) % 2 || (abs(e - fix)) % 2) continue;
	if (e >= L && e <= R) {
	    if (type <= 1)
		ret = min(ret, calc(e, fix));
	    else ret = min(ret, calc(fix, e));
	}
    }

    return ret;
}

ll oX[MAX], oY[MAX];

pii rotate (ll a, ll b) {
    return pii(a - b, a + b);
}

int main () {
    scanf ("%lld", &n);
    for (ll i = 0; i < n; i++) {
	ll a, b;
	scanf ("%lld%lld", &a, &b);
	P[i] = pii(a, b);		

	oX[i] = a;
	oY[i] = b;
    }
    scanf ("%lld", &d);

    sort(oX, oX + n);
    sort(oY, oY + n);

    pii M = pii(oX[n / 2] - oY[n / 2], oX[n / 2] + oY[n / 2]); 
    
    ll Lx, Ly, Rx, Ry;

    pii P1 = rotate (P[0].first - d, P[0].second);
    pii P2 = rotate (P[0].first + d, P[0].second);
    
    Lx = P1.first;
    Rx = P2.first;

    Ly = P1.second;
    Ry = P2.second;

    debug ("%lld %lld -- %lld %lld\n", P1.first, P1.second, P2.first, P2.second);
    
    for (ll i = 1; i < n; i++) {
	P1 = rotate (P[i].first - d, P[i].second);
	P2 = rotate (P[i].first + d, P[i].second);

	debug ("%lld %lld -- %lld %lld\n", P1.first, P1.second, P2.first, P2.second);
	
	Lx = max (Lx, P1.first);
	Rx = min (Rx, P2.first);

	Ly = max (Ly, P1.second);
	Ry = min (Ry, P2.second);
    }
    
    debug ("Interseccção %lld %lld -- %lld %lld\n", Lx, Rx, Ly, Ry); 	

    
    
    if (Lx > Rx || Ly > Ry) {
	debug ("Intersecção nula\n");
	puts("impossible");
	return 0;
    }

    if (M.first >= Lx && M.first <= Rx && M.second >= Ly && M.second <= Ry) {
	debug ("Mediana dentro\n");

	//M = pii(7, 1);
	
	debug ("--> %lld %lld\n", (M.first + M.second) / 2, (M.second - M.first) / 2);
	
	printf ("%lld\n", calc (M.first, M.second));
	return 0;
    }

    debug ("Mediana fora %lld\n", calc(M.first, M.second));

    //debug ("Interseccção %lld %lld -- %lld %lld\n", Lx, Rx, Ly, Ry);  
    
    ll resp = 1e17;

    resp = min(resp, ternary(Lx, Rx, Ly, 0));
    resp = min(resp, ternary(Lx, Rx, Ry, 1));
    resp = min(resp, ternary(Ly, Ry, Lx, 2));
    resp = min(resp, ternary(Ly, Ry, Rx, 3));

    // resp = brute (Lx, Rx, Ly, Ry);
    
    if (resp >= 1e17) {
	puts("impossible");
    } else printf ("%lld\n", resp);
    
    return 0;
}




