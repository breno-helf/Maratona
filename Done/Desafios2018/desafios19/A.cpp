#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll l, r, k, x, y;

    cin >> l >> r >> x >> y >> k;

    for (int a = l; a <= r; a++) {
        if (a % k != 0) continue;
        int b = a / k;
        if (b >= x && b <= y) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';
    
    return 0;
}
