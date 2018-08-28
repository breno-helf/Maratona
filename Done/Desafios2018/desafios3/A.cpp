//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 10;

int crivo[MAX];

int main() {
    int q;
    cin >> q;

    set<int> DIV;
    int num = q;
    for (ll i = 2; i <= 1e5; i++) {
        if (crivo[i] == 0) {
            for (ll k = i * i; k <= 1e5; k += i) {
                crivo[k] = i;
            }

            while (num % i == 0) {
                DIV.insert(i);
                num /= i;
            }
        }
    }

    if ((int)DIV.size() == 1 && num == 1) puts("yes");
    else if ((int)DIV.size() == 0 && num != 1) puts("yes");
    else puts("no");
    return 0;
}


