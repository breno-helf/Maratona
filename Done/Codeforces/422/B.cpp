//If you are trying to hack me I wish you can get it, Good Luck :D.
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

int n, m;
string s, t;
vector<int> resp;
map<char, int> mrk;
map<char, vector<int> > M;

void calc (int pos) {
    vector<int> cur;
    int j = 0;
    for (int i = pos; i < pos + n; i++) {
	if (s[j] != t[i]) cur.pb(j++);
	else j++;
    }
    if (cur.size() < resp.size()) resp = cur;
}

int main () {
    cin >> n >> m;
    cin >> s >> t;

    for (int i = 0; i < n; i++) resp.pb(i);
    
    for (int i = 0; i <= m - n; i++) {
	calc(i);
    }

    cout << resp.size() << '\n';
    for (auto e : resp)
	cout << e + 1 << ' ';
    cout << '\n';
}

