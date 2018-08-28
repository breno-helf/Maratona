//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll generate(int pos, string& s, ll cur) {
    if (pos == (int)s.size()) return cur;
    
    ll nxt = 0;
    if (s[pos] == '0') nxt = cur;
    else nxt = (1LL<<(pos + 1)) - 1 - cur;

    return generate(pos + 1, s, nxt);
    
}

int main() {
    int n;
    string r, s;
    cin >> n;
    cin >> r >> s;
    reverse(r.begin(), r.end());
    reverse(s.begin(), s.end());
    
    ll R = generate(0, r, 0);
    ll S = generate(0, s, 0);
    //debug("--> %lld %lld\n", R, S);
    cout << S - R - 1 << '\n';

    return 0;
}

