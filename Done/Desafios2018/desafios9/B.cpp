#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

typedef long long ll;

const double EPS = 1e-9;

// seja A = ((a + p - 1) / p) * p
// [A, b] ou [A + mmc(p, q), b] -
// Dependendo se A * p eh dominante

ll countDiv(ll l, ll r, ll num) {
    if (num > r) return 0;    
    
    ll L = ((l + num - 1) / num) * num;

    debug("==> (%lld, %lld) [%lld]\n", L, r, num);

    if (L <= r) return (r - L) / num + 1;
    else return 0;
}

int main() {
    ifstream cin("jealous.in");
    ofstream cout("jealous.out");
    
    ll a, b, p, q;
    
    cin >> a >> b >> p >> q;

    ll P = p, M = p * q;
    ll ans = 0;
    
    while (true) {
        ll want = countDiv(a, b, P);
        ll trash = countDiv(a, b, P * q);
        if (want == 0) break;
        if ((log10((double)P) + log10((double)q)) > (18.0 + EPS)) trash = 0;
        
        ans += (want - trash);
        
        debug("--> Want is %lld (%lld) \n--> Trash is %lld (%lld) \n\n", want, P, trash, P * q);
        if ((log10((double)P) + log10((double)M)) > (18.0 + EPS)) break; 
        P *= M;
    }
    
    cout << ans << '\n';

    return 0;
}
