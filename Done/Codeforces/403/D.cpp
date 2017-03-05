//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int, string> pis;
typedef pair<string, int> psi;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
string name[2][MAX];
string sh[2][MAX];
int t[MAX];

set<pis> ans;
set<psi> pri;
set<string> used;
map<string, int> cnt, idx;

void rec (string s, int id) {
    if (used.find(s) == used.end()) {
	ans.insert(mp(id, s));
	used.insert(s);
	idx[s] = id;
    }
    else {
	int ui = idx[s];
	if (t[id] == 1 && t[ui] == 1) {
	    cout << "NO" << '\n';
	    exit(0);
	}
	ans.erase(mp(ui, t[ui] ? sh[1][ui] : sh[0][ui]));
	used.erase(t[ui] ? sh[1][ui] : sh[0][ui]);
	idx[t[ui] ? sh[1][ui] : sh[0][ui]] = 0;
	t[id] = 1;
	t[ui] = 1;
	rec(sh[1][id], id);
	rec(sh[1][ui], ui);
    }
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
	cin >> name[0][i] >> name[1][i];
	sh[0][i] = sh[1][i] = "";

	sh[0][i] += name[0][i][0];
	sh[0][i] += name[0][i][1];
	sh[0][i] += name[0][i][2];

	sh[1][i] += name[0][i][0];
	sh[1][i] += name[0][i][1];
	sh[1][i] += name[1][i][0];
	
	pri.insert(mp(sh[0][i], i));
	cnt[sh[0][i]]++;
    }

    for (auto e : pri) {
	string s = e.first;
	int id = e.second;
	if (cnt[s] > 1) t[id] = 1;
	else t[id] = 0;
    }

    for (int i = 1; i <= n; i++)
	rec(t[i] ? sh[1][i] : sh[0][i], i);
    
    cout << "YES" << '\n';
    for (auto e : ans) {
	cout << e.second << '\n';
    }
    return 0;
}
