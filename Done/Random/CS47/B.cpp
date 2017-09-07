//This code was written by Breno Moura, Codeforces Handle: Brelf

//From University of São Paulo - USP

//If you are trying to hack me I wish you can get it, Good Luck :D

#include <bits/stdc++.h>

using namespace std;



#define debug(args...) fprintf (stderr,args)

#define pb push_back

#define mp make_pair



typedef long long ll;

typedef pair<int,int> pii;

typedef pair<ll,ll> pll;



const int MAX = 112345;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



int main() {

    int n;

    cin >> n;    

    for (ll a = 1; a <= 100000LL; a++) {

        ll c = a - a * a - 2 * n;

        if (c > 0) continue;

        ll delta = 1 - 4 * c;

        ll s = sqrt(delta);

        if (s * s != delta) continue;

        ll b = s - 1;

        if (b % 2 || b/2 <= a) continue;

        cout << a << ' ' << b/2 << '\n';

        return 0;

    }

    cout << -1 << '\n';

}
