//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e6 + 10;

int T;
ll A, B, P;
vector<ll> primes;
int crivo[MAX];

int pai[MAX], sz[MAX];

int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

int une(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (sz[a] < sz[b]) swap(a, b);

    pai[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main() {
    for (ll i = 2; i < MAX; i++) {
        if (crivo[i] == 0) {
            primes.push_back((ll)i);
            for (ll k = i * i; k < MAX; k += i) crivo[k] = i;
        }
    }    
    
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%lld %lld %lld", &A, &B, &P);

        for (ll k = A; k <= B; k++) {
            pai[k - A] = k - A;
            sz[k - A] = 1;
        }
        
        ll ans = B - A + 1;
        
        for (ll prime : primes) {
            if (prime < P) continue;
            ll last = -1;

            for (ll k = ((A + prime - 1) / prime) * prime; k <= B; k += prime) {
                if (last == -1) last = k;
                else {
                    ans -= une(last - A, k - A);
                }
            }
        }
        
        printf("Case #%d: %lld\n", t, ans);
    }

    return 0;
}
