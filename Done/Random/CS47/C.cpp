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



const int MAX = 312;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



ll lcm(ll a, ll b) {

    return (a * b) / __gcd(a, b);

}



int n, m;

ll a[MAX][MAX];

ll U[MAX], V[MAX];



void fail() {

    puts("-1");

    exit(0);

}



int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {

        ll L = 1;

        for (int j = 1; j <= m; j++) {

            cin >> a[i][j];

            L = lcm(L, a[i][j]);

            if (L > (ll)1e9) {

                fail();

            }

        }

        V[i] = L;

    }

    

    for (int j = 1; j <= m; j++) {

        ll L = 1;

        for (int i = 1; i <= n; i++) {

            L = lcm(L, a[i][j]);

            if (L > (ll)1e9) {

                fail();

            }

        }

        U[j] = L;

    }

    

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (__gcd(V[i], U[j]) != a[i][j])

                fail();

        }   

    }

    

    for (int i = 1; i <= n; i++)

        cout << V[i] << ' ';

    cout << '\n';

    for (int j = 1; j <= m; j++)

        cout << U[j] << ' ';

    cout << '\n';

}
