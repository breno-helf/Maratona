//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123456;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s, t, p, rs;
int l, r, resp;
int z[MAX];

void z_function (string a) {
    l = r = 0;
    for (int i = 1; i < (int)a.size(); i++) {
	if (i <= r)
	    z[i] = min(z[i - l], r - i + 1);

	while ((z[i] + i) < (int)a.size() && a[z[i] + i] == a[z[i]])
	    z[i]++;

	if (r < (i + z[i] - 1)) {
	    l = i;
	    r = i + z[i]  - 1;
	}		
    }
}


int main () {
    cin >> s >> t;
    if (s.size() != t.size()) {
	cout << "No" << '\n';
	return 0;
    }
    //rs = s;
    //reverse(rs.begin(), rs.end());

    p = t + '#' + s;

    //cout << p << '\n';
    
    vector<int> test;

    resp = -1;
    
    z_function(p);
    for (int i = t.size() + 1; i < (int)p.size(); i++) {
	debug("%d -- %d\n", z[i], ((int)p.size() - i));
	if(z[i] == ((int)p.size() - i))
	    test.pb(s.size() - z[i]);
    }

    debug("\n");    
    
    for (int e : test) {
	string a = "";
	debug("Testei %d\n", e);

	for (int i = e; i < (int)s.size(); i++)
	    a += s[i];

	for (int i = (e - 1); i >= 0; i--) {
	    a += s[i];
	}

	//	cout << e << ' ' << a << " --- " << t << '\n'; 
	
	if(a == t) {
	    resp = e;
	    break;
	}
    }

    if(resp == -1) {
 	cout << "No" << '\n';		
    }
    else {
	cout << "Yes" << '\n';
	cout << resp << '\n';
    }
}





