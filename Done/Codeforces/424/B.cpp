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

string L1, L2, s;

map<char, char> M;



int main() {
    cin >> L1 >> L2 >> s;

    for (int i = 0; i < 26; i++) {
	M[L1[i]] = L2[i];
	M[L1[i] - 'a' + 'A'] = L2[i] - 'a' + 'A';
    }

    for (int i = 0; i < (int)s.size(); i++) {
	if (M.find(s[i]) != M.end())
	    cout << M[s[i]];
	else cout << s[i];
    }
    cout << '\n';
}

