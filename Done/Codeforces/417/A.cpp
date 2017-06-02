//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 23112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int a[4][4];

int main () {
    for (int i = 0; i < 4; i++) {
	for (int j = 0; j < 4; j++) {
	    cin >> a[i][j];
	}
    }

    bool ok = false;
    
    for (int i = 0; i < 4; i++) {
	int f = (i + 2) % 4;
	if ((a[i][1] || a[i][0] || a[i][2]) && a[i][3]) {
	    ok = true;
	}

	if (a[f][3] && a[i][1])
	    ok = true;
	
	int p = (i + 3) % 4;
	int n = (i + 1) % 4;
	
	if (a[i][0] && a[p][3])
	    ok = true;
	if (a[i][2] && a[n][3])
	    ok = true;
    }
    
    if (ok)
	puts("YES");
    else
	puts("NO");
    
}

