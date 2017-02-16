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

const int MAX = 51;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, q;
map<char, set<string> > op;
set<string> used;
ll ways(string cur) {
    if ((int)cur.size() == n) {
	if (used.find(cur) == used.end()) {
	    used.insert(cur);
	    return 1LL;
	}
	else
	    return 0LL;
    }
    ll ret = 0LL;
    int tam = cur.size();
    for (auto e : op[cur[0]]) {
	string nxt = "";
	nxt += e;
	for (int k = 1; k < tam; k++) nxt += cur[k];
	ret += ways(nxt);
    }	
    return ret;
}

int main () {
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
	string a;
	char b;
	cin >> a >> b;
	op[b].insert(a);
    }
    cout << ways("a") << '\n';
}


