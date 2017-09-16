//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 12312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string r, s;
set<string> accepted;

int main() {
    cin >> r >> s;
    accepted.insert(r);
    int tam = r.size();
    if (tam >= 8) {
	for (int i = 0; i < tam; i++) {
	    string cur = "";
	    string cur2 = "";
	    for (int j = 0; j < tam; j++) {
		cur2 += r[j];
		if (i == j) continue;
		cur += r[j];
	    }
	    accepted.insert(cur);
	    for (char c = 'a'; c <= 'z'; c++) {
		cur2[i] = c;
		accepted.insert(cur2);
	    }

	    for (char c = 'A'; c <= 'Z'; c++) {
		cur2[i] = c;
		accepted.insert(cur2);
	    }
	}
    }

    if ((accepted.find(s) == accepted.end())) cout << "no" << '\n';
    else cout << "yes" << '\n';
}

