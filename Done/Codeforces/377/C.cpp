//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=122312;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll x, y, z;
ll m;

ll calc(ll b, ll d, ll s) {
    ll resp = 0;
    d -= b - 1;
    s -= b - 1;
    b = 0;
    resp += max(0LL, - d) + max(0LL, - s);
    if(d > 0LL) {
        if(d == 1)
            d = 0;
        else {
            b -= d;
            s -= d - 1;
            d = 0;
            resp += max(0LL, - s) + max(0LL, - b);
        }
    }
    if(s >= 0LL) {
        if(s == 1)
            s = 0;
        else {
            b -= s;
            d -= s;
            s = 0;
            resp += max(0LL, - b) + max(0LL, - d);
        }
    }
    return resp;
}

int main() {
    cin >> x >> y >> z;
    m = calc(x, y, z);
    vector<int> p;
    p.pb(1);p.pb(2);p.pb(3);
    for(int i = 1; i < 6; i++) {
        next_permutation(p.begin(), p.end());
        m = min(m, calc((p[0] == 1) ? x : ((p[0] == 2) ? y : z), (p[1] == 1) ? x : ((p[1] == 2) ? y : z), (p[2] == 1) ? x : ((p[2] == 2) ? y : z)));
    }
    cout << m << '\n';
}
