#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = (int)2e7;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll a, b, c;

int main () {
    ifstream cin ("input.txt");
    ofstream cout ("output.txt");

    
    cin >> a >> b >> c;
    int idx[2] = {0, 0};
    ll x[2] = {1, 1};
    int len = -1;
    int ans = -1;
    
    while (idx[0] <= MAX) {
	x[0] = (a*x[0] + x[0] % b) % c;
	idx[0] += 1;
	x[1] = (a*x[1] + x[1] % b) % c;
	x[1] = (a*x[1] + x[1] % b) % c;

	if(x[1] == x[0]) {
	    len = 1;
	    ll X = (a*x[1] + x[1] % b) % c ;
	    while (X != x[1]) {
		len++;
		X = (a*X + X % b) % c;
	    }
	    break;
	}
    }
    
    if (len != -1) {
	idx[0] = idx[1] = 0;
	x[0] = x[1] = 1;
	while (idx[1] < len) {
	    idx[1]++;
	    x[1] = (a*x[1] + x[1] % b) % c;
	}
	
	while (x[1] != x[0]) {
	    idx[0]++;
	    idx[1]++;
	    x[0] = (a*x[0] + x[0] % b) % c;
	    x[1] = (a*x[1] + x[1] % b) % c;
	}
	if(idx[1] <= MAX)
	    ans = idx[1];
	else
	    ans = -1;
    }
    else
	ans = -1;
    cout << ans << '\n';
}

