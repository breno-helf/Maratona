//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 13212;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll h;

int main() {
    cin >> h;
    ll ans = h;
    ll cur = 1;
    
    for (ll k = h - 1; k > 0; k--) {
        cur += 2;
        ans += (cur * cur - (cur - 2) * (cur - 2)) * k;
        //debug("adding %lld\n", (cur * cur - (cur - 2) * (cur - 2)) * k);
    }
    cout << ans << '\n';
}
