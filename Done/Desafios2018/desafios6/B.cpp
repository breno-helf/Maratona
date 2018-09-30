#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args);

typedef long long ll;

ll v[12];

ll sq(ll x) {
    return x * x;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        ll d;
        cin >> v[0] >> v[1] >> v[2] >> d;
        ll ans = 0;
        ll st = 0;

        for (int i = 0; i < 3; i++) {
            st += sq(v[i]);
        }
        
        for (int i = 0; i < 3; i++) {
            ll cur = st - sq(v[i]) + sq(v[i] + d);
            ll men = v[i] + d;
            for (int j = 0; j < 3; j++) if (j != i) men = min(men, v[j]);
            
            ans = max(ans, cur + 7LL * men);
        } 
        
        if (d <= 700) {
            for (ll dA = 0; dA <= d; dA++) {
                for (ll dB = 0; dB <= d - dA; dB++) {
                    ll dC = d - dA - dB;
                    assert((dA + dB + dC) == d);
                    ans = max(ans, sq(v[0] + dA) + sq(v[1] + dB) + sq(v[2] + dC) + 7LL * min(v[0] + dA, min(v[1] + dB, v[2] + dC)));
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
