#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k;
ll w[MAX];
ll p;

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
	cin >> w[i];
	debug("-- %lld\n", p);
	ll add = (w[i] + k - 1) / k;
	debug("add %lld\n", add);
	p += add;
    }
    cout << (p + 1)/2 << '\n';
}


