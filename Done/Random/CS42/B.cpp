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



const int MAX = 1123;

const int INF = 0x3f3f3f3f;

const ll  MOD = 1000000007;



string s, a, b;



int main() {

    cin >> s >> a >> b;

    int n = a.size();

    int tam = s.size();

    for (int i = 0; i < tam; i++) {

        bool A = true, B = true;

        for (int j = 0; j < n; j++) {

            if (s[i + j] != a[j]) A = false;

            if (s[i + j] != b[j]) B = false;

            if (!A && !B) break;

        }

        if (!A && !B) cout << s[i];

        else if (A) {

            cout << b;

            i += n - 1;

        } else if (B) {

            cout << a;

            i += n - 1;

        }

    }

    cout << '\n';

}
