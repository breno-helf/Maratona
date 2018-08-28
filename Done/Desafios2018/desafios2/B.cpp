//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e6 + 10;
const ll  MOD = 1000000007;

int n, m;
string p;
int z[MAX];
int st[MAX];
vector<int> pos;

bool check(int i, int k) {
    if (i >= k) return true;
    
    if (z[pos[k] - pos[i]] != ((int)p.size() - pos[k] + pos[i]))
        return false;
    return true;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> p;
    

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        pos.push_back(x - 1);
        st[x] = 1;
    }

    int L = 0, R = 0;
    for (int i = 1; i < (int)p.size(); i++) {
        if (i > R) {
            L = R = i;
            while (R < (int)p.size() && p[R - L] == p[R]) R++;
            z[i] = R - L; R--;
        } else {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while (R < (int)p.size() && p[R-L] == p[R]) R++;
                z[i] = R - L; R--;
            }
        }
    }        

    
    unordered_set<int> S;
    
    for (int i = 0; i < m - 1; i++) {
        int last = i;
        for (int k = i + 1; k < m && (pos[k] - pos[i]) < (int)p.size(); k++) {
            if (check(i, k) == false) {
                cout << 0 << '\n';
                return 0;
            }
            S.insert(pos[k] - pos[i]);
            if (S.size() == p.size()) break;
            last = k;
        }
        i = last;
        if (S.size() == p.size()) break;
    }

    int ans = 1;
    int k = -1;

    for (int i = 1; i <= n; i++) {

        if (st[i] == 0) {
            if (k == -1) ans = (26LL * (ll)ans) % (ll)MOD;
            else k++;
        } else {
            k = 1;
        }

        if (k == (int)p.size()) k = -1;
    }

    cout << ans << '\n';    
}
