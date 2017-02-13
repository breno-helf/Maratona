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

int n;
map<string, int> m;
vector<int> pile[MAX];

int solve () {
    int ret = 0;

    if (n == 1) {
	if (pile[0].back() == 1) {
	    ret++;
	    pile[0].pop_back();
	}
	if (pile[0].size() > 3)
	    return -1;
	else {
	    if (pile[0].size() == 0)
		return ret;
	    if (pile[0].size() == 3)
		return ret + 2;
	    else
		return ret + 1;
	}
    }

    int e = 0;
    
    for (int i = 0; i < n; i++) {
	if (pile[i].back() == 1) {
	    ret++;
	    pile[i].pop_back();
	}
	if (pile[i].size() >= 2) e = 1;
	ret += pile[i].size();
    }
    return ret - e;
}
int main () {
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    m["c"] = 0;
    m["bw"] = 1;

    cin >> n;

    for (int i = 0; i < n; i++) {
	int tam;
	cin >> tam;
	for (int j = 0; j < tam; j++) {
	    string s;
	    cin >> s;
	    if (pile[i].empty() || pile[i].back() != m[s])
		pile[i].pb(m[s]);
	}
	reverse(pile[i].begin(), pile[i].end());
    }

    cout << solve() << '\n';
}

