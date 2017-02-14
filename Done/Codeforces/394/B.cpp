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

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, l;
bool resp;
vector<int> a, b;

int main () {
    resp = false;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
	int A;
	cin >> A;
	a.pb(A);
    }
    
    for (int i = 0; i < n; i++) {
	int B;
	cin >> B;
	b.pb(B);
    }

    for (int i = 0; i < n; i++) {
	vector<int> c;
	int dist = a[0] - b[i];
	if (dist < 0) dist += l;	
	c.pb(a[0]);
	
	for (int j = i + 1; j < n; j++) {
	    c.pb((b[j] + dist) % l);
	}

	for (int j = 0; j < i; j++) {
	    c.pb((b[j] + dist) % l);
	}
	sort(c.begin(), c.end());

	// for (int j = 0; j < n; j++)
	//     cout << c[j] << ' ';
	// cout << "  <-- " << dist << '\n';

	if (c == a)
	    resp = true;
    }
    if (resp)
	cout << "YES\n";
    else
	cout << "NO\n";
    return 0;
}

