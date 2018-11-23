#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> v;

int main() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back(pll(b, a));
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    ll ans = 0;

    for (int i = 0; i < m; i++) {
        ll b = v[i].first, a = v[i].second;
        
        ans += b * min(a, n);

        n -= a;
        n = max(n, 0LL);
    }

    cout << ans << '\n';

    return 0;
}
