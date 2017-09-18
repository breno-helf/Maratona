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

ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    int p = 1;
    for (int i = 0; i < k; i++) p *= 10;
    printf("%lld\n", mmc(n, p));
    return 0;
}

