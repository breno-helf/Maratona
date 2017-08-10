#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, a, b;

int main() {
    scanf("%lld", &n);
    while(n--) {
	bool ok = true;
	scanf(" %lld %lld", &a, &b);
	
	ll num = a * b;
	ll l = 1, r = 1e6 + 10;
	ll c = -1;

	//debug(")) %lld\n", num);
	
	while (l < r) {
	    ll m = (l + r) / 2;
	    if (m * m * m < num) l = m + 1;
	    else if (m * m * m > num) {
		//debug("> %lld %lld\n", m, num);
		r = m - 1;
	    }
	    else {
		c = m;
		break;
	    }
	}

	//debug("--> %lld %lld\n", l, r);
	
	if (c == -1) {
	    if (l * l * l == num) c = l;
	    else if (r * r * r == num) c = r;
	}

	if (c == -1) ok = false;
	else {
	    if (a % c != 0 || b % c != 0) ok = false;
	}

	//debug("%lld\n", c);
	
	if (ok) puts("Yes");
	else puts("No");
    }
}

