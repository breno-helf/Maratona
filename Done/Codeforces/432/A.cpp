//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2131;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k, t;

int main() {
    scanf("%lld%lld%lld", &n, &k, &t);
    ll resp = 0;
    if (t >= k && t <= n) resp = k;
    else if (t < k) resp = t % k;
    else {
	resp = k - (t - n) % k;
	if (resp == k) resp = 0;
    }
    printf("%lld\n", resp);
}

