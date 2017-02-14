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

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, l, r;

int w[MAX], a[MAX], p[MAX], inv[MAX];
int b[MAX], s[MAX];
bool resp;

int main () {
    resp = true;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
	cin >> w[i];
	w[i] *= -1;
    }
    for (int i = 0; i < n; i++) {
	cin >> p[i];
	inv[p[i] - 1] = i;
    }
    for (int i = 0; i < n; i++) {
	a[p[i] - 1] = l + w[i];
	b[i] = l;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] >= a[i]){
	    if ((a[i - 1] - a[i] + 1) > (r - l)) {
		resp = false;
		break;
	    } else {
		//		debug ("%d ---> %d %d ==== ", i, b[i], a[i]);
		b[i] += (a[i - 1] - a[i] + 1);
		a[i] = a[i - 1] + 1;
		//		debug ("%d ---> %d %d\n", i, b[i], a[i]);

	    }	    
	}	
    }

    if (resp) {
	for (int i = 0; i < n; i++) { 
	    s[inv[i]] = b[i];
	}
	for (int i = 0; i < n; i++)
	    cout << s[i] << ' ';
	cout << '\n';
    } else {
	cout << -1 << '\n';
    }
}

