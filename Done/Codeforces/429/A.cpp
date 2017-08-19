//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, k;
string s;
int v[MAX];
int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) v[s[i] - 'a']++;
    int m = 0;
    for (int i = 0; i < MAX; i++) m = max(m, v[i]);

    string r = (m <= k) ? "YES" : "NO";
    cout << r << '\n';
    return 0;
}
