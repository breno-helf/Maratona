//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 312321;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

set<string> S;

int n, k;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string uni, name;
        cin >> uni >> name;
        if (S.count(uni) == 0) {
            if (k) {
                k--;
                S.insert(uni);
                cout << name << '\n';
            }
        }
    }
}
