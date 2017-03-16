//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
map<string, int> m;
ll resp;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    m["Tetrahedron"] = 4;
    m["Cube"] = 6;
    m["Octahedron"] = 8;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;
    resp = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
	string s;
	cin >> s;
	resp += m[s];
    }
    cout << resp << '\n';
}

