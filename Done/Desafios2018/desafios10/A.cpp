#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 1e6 + 500;

ll t, n, k;
ll crivo[MAX];
vector<ll> primes;
map<ll, ll> M;

void fact(ll K) {    
    for (ll p : primes) {
        if (K % p == 0) {                
            while (K % p == 0) {
                K /= p;
                M[p]++;
            }
        }

        if (K == 1) break;
    }
        
    if (K != 1) {
        M[K]++;
    }
}


int main() {
    for (ll i = 2; i < MAX; i++) {
        if (!crivo[i]) {
            primes.push_back(i);
            for (ll K = i * i; K < MAX; K += i) crivo[K] = i; 
        }
    }

    cin >> t;

    while (t--) {
        cin >> n >> k;
        
        M.clear();
        fact(k);
        
        ll ans = LLONG_MAX;
        //printf("%lld\n", ans);
        for (auto e : M) {
            ll cur = 0;
            ll P = e.first;
            ll D = e.first;
            
            while (true) {
                //printf("--> %lld %lld %lld\n", P, n / P, cur);
                cur += n / P;
                if (P > ((n / D) + 1)) break;
                P *= D;
            }

            ans = min(ans, cur / e.second);

        }

        if (ans == LLONG_MAX) ans = 0;

        cout << ans << '\n';
    }

    return 0;
}
