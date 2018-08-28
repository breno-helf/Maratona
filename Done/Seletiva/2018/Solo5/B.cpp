//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const ll  MOD = 1000000007;
int crivo[MAX];
int n;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i < MAX; i++) {
        if (crivo[i] == 0) {
            for (int k = i * i; k < MAX; k += i) crivo[k] = i;
        }        
    }

    map<int, int> factors;
    ll ans = 1;
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 1) {
            if (crivo[num] > 0) {
                factors[crivo[num]]++;
                num /= crivo[num];
            } else {
                factors[num]++;
                num = 1;
            }
        }
    }

    for (auto e : factors) {
        ans = (ans * ((ll)e.second + 1LL)) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
