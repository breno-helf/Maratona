//If you are trying to hack me I wish you can get it, Good Luck :D.
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


int n;
string G[3];
map<char, int> S;
int g[3];
int best[3];
int ans, id;

int main() {
    cin >> n;
    
    for (int i = 0; i < 3; i++) {
        cin >> G[i];
        for (char k : G[i]) {
            S[k]++;
            g[i] = max(g[i], S[k]);
        }
        S.clear();

        if (n == 1 && g[i] == G[i].size()) best[i] = g[i] - 1;
        else best[i] = min((int)G[i].size(), g[i] + n);
        
        if (best[i] > ans) {
            ans = best[i];
            id = i;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (best[i] == ans && i != id) {
            cout << "Draw\n";
            return 0;
        }
    }

    if (id == 0) cout << "Kuro\n";
    if (id == 1) cout << "Shiro\n";
    if (id == 2) cout << "Katie\n";
}
