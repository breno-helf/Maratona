//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 10;

int n, d, T;
ll a[MAX];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &d);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        ll targ = -1;
        ll ans = 0;
        
        for (int s = 0; s < d; s++) {
            ll sum = 0;
            ll el = 0;

            for (int k = 0; (s + k * d) < n; k++) {
                int i = (s + k * d);
                sum += a[i];
                el++;
            }
            
            if (sum % el != 0) {
                debug("Sum %lld is not divisible by number of elements %lld\n", sum, el);
                ans = -1;
                break;
            }

            ll cur = sum / el;
            
            if (targ == -1) {
                targ = cur;
            } else if (targ != cur) {
                debug("target %lld is different than cur %lld\n", targ, cur);
                ans = -1;
                break;
            }

            ll add = 0;
            deque<pll> Have;
            for (int k = 0; (s + k * d) < n; k++) {
                int i = (s + k * d);
                if (a[i] > cur) {
                    Have.push_back(pll(a[i] - cur, k));
                }               
            }

            for (int k = 0; (s + k * d) < n; k++) {
                int i = (s + k * d);
                if (a[i] < cur) {
                    while (a[i] < cur) {
                        ll H = Have.front().first;
                        ll pos = Have.front().second;
                        ll D = abs(pos - k);
                        Have.pop_front();
                        
                        if (H >= (cur - a[i])) {
                            add += (cur - a[i]) * D;
                            H -= (cur - a[i]);
                            a[i] = cur;
                            if (H > 0) Have.push_front(pll(H, pos));
                        } else {
                            add += H * D;
                            a[i] += H;
                            H = 0;
                        }
                    }
                }
            }
            
            assert(Have.empty());
            
            debug("Need %lld moves for subsetarray starting in %d\n", add, s);
            
            ans += add;
            
        }
        
        printf("%lld\n", ans);
        
    }
    
    
    return 0;
}


