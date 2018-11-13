#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<ll> nums;
string s;
int n;

const ll LIM = 1e6;

ll calc(int i, int j) {
    if ((i - 0) > 1 && s[0] == '0') return -1;
    if ((j - i) > 1 && s[i] == '0') return -1;
    if ((n - j) > 1 && s[j] == '0') return -1;
    
    ll cur = 0;
    ll sum = 0;

    for (int k = 0; k < i; k++) {
        cur = (cur * 10LL) + (ll)(s[k] - '0');
    }
    if (cur > LIM) return -1;
    sum += cur;
    cur = 0;

    for (int k = i; k < j; k++) {
        cur = (cur * 10LL) + (ll)(s[k] - '0');
    }
    if (cur > LIM) return -1;
    sum += cur;
    cur = 0;
    
    for (int k = j; k < n; k++) {
        cur = (cur * 10LL) + (ll)(s[k] - '0');
    }
    if (cur > LIM) return -1;   
    sum += cur;
    
    return sum;
}

int main() {
    cin >> s;
    n = s.size();

    if (n > 21) {
        cout << -1 << '\n';
        return 0;
    }
        
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll cur = calc(i, j);
            //printf("%d %d -- %d\n", i, j, cur);
            if (cur >= 0) nums.insert(cur);
        }
    }
    
    ll ans;

    if (!nums.empty()) ans = *(--nums.end());
    else ans = -1;
    
    cout << ans << '\n';
}
