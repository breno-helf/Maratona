#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

bool test(ll v) {
    ll l = 0;
    ll c = 1;
    while (v >= c) {
        //cout << "==>  " << v << ' ' << c << ' ' << l << '\n';
        l += v / c;
        c *= k;
    }
    //cout << "==>  " << v << ' ' << c << ' ' << l << '\n';
    
    return (l >= n);
}

int main() {
    cin >> n >> k;

    int l = 0, r = 1e9 + 10;
    
    while (l < r) {
        int mid = (l + r) / 2;
        bool ok = test(mid);
        //cout << mid << ' ' << (ok ? "MORE THAN " : "LESS THAN ") << n << "\n\n";
        
        if (ok) {
            r = mid;
        } else {
            l = mid + 1;
        }            
    }

    cout << l << '\n';
}
