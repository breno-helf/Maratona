//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 21312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, m;
int cur;
int main() {
    cur = 2;
    cin >> n >> m;
    for (ll i = 2; i <= n; i++) {
	cur *= 2;
	if (cur > m) break;
    }    
    
    cout << m % cur << '\n';
}

