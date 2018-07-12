//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 423432;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll k, n, s, p;

int main() {
    cin >> k >> n >> s >> p;
    ll ans = (((n + s - 1) / s) * k + p - 1) / p;

    cout << ans << '\n';
}
