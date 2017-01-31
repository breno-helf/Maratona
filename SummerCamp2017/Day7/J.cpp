//This code was made by Breno Moura, Codeforces Handle: Brelf
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

int n, a, b;
int z, u, d;
int saldo[3];
set<int> pos[3];
string s;

int main () {
    cin.sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);
    
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    z = u = d = 0;

    cin >> n >> a >> b;
    cin >> s;

    int tam = s.size();
	
    for (int i = 0; i < tam; i++) {
	char e = s[i];
	if (e == '0') {
	    z++;
	    pos[0].insert(i);
	} else if (e == '1') {
	    u++;
	    pos[1].insert(i);
	} else if (e == '2') {
	    d++;
	    pos[2].insert(i);
	}
    }

    
    saldo[0] = z - a;
    saldo[1] = u - b;
    saldo[2] = d - (n - (a + b));

    if ((n - (a + b)) < 0) {
	cout << -1 << '\n';
	return 0;
    }

    // for (int i = 0; i < 3; i++)
    // 	debug("-- saldo %d eh %d\n", i, saldo[i]);
    
    int resp = 0;
    for (int i = 0; i < tam; i++) {
	int num = s[i] - '0';
	if(saldo[num] > 0) {
	    int t;
	    resp++;
	    for (int k = 0; k < 3; k++) {
		if (k != num && saldo[k] < 0)
		    t = k;
	    }
	    s[i] = '0' + t;
	    pos[num].erase(i);
	    pos[t].insert(i);
	    saldo[num]--;
	    saldo[t]++;
	}
    }

    cout << resp << '\n';
    cout << s << '\n';

}
