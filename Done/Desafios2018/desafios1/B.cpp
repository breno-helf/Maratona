//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll A, B;
int n;
ll l, t, m;

ll PA(ll num, ll A1, ll AN) {
    return (((A1 + AN) * num) / 2);
}

ll f(ll x) {
    return (A + B * (x - 1));
}

int main() {
    cin >> A >> B >> n;

    for (int i = 0; i < n; i++) {

        cin >> l >> t >> m;

        if ((A + B * (l - 1)) > t) printf("-1\n");
        else {
            ll lo = l, hi = l + 1e6 + 10; 
            
            // for (int k = 1; k <= 5; k++) {
            //     printf("%lld \n", func(k));
            // }
            
            // printf("\n--> %lld %lld %lld\n\n", l, t, m);
            
            while (lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                               
                if (PA(mid - l + 1, f(l), f(mid)) > t * m || f(mid) > t) hi = mid - 1;
                else lo = mid;
            }

            //printf("%lld %lld -- %lld %lld -- %lld %lld %lld\n", PA(lo - l + 1, f(l), f(lo)), t * m, f(lo), t, l, lo, f(l));
            
            printf("%lld\n", lo);
        }
    }
    return 0;
}
