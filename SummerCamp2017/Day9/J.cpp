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

const int MAX = 412;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;

double x[MAX], r[MAX], p[MAX];

int main () {

    ifstream cin ("input.txt");
    ofstream cout("output.txt");
    
    cin >> n;

    for (int i = 0; i < n; i++)
	cin >> x[i];

    double d;
    double ans = 1e10;
    
    
    for (int i = 0; i < n; i++) {
	for (int j = i + 1; j < n; j++) {
	    if (i == j)	continue;
	    d = (x[j] - x[i])/((double)(j - i));
	    double cur = 0;
	    r[i] = x[i];
	    
	    for (int k = i - 1; k >= 0; k--) {
		cur += abs(x[k] - (r[k + 1] - d));
		r[k] = r[k + 1] - d;
	    }

	    r[j] = x[j];
	    
	    for (int k = i + 1; k < j; k++) {
		cur += abs(x[k] - (r[k - 1] + d));
		r[k] = r[k - 1] + d;
	    }

	    for (int k = j + 1; k < n; k++) {
		cur += abs(x[k] - (r[k - 1] + d));
		r[k] = r[k - 1] + d;		
	    }

	    if (cur < ans) {
		for (int k = 0; k < n; k++)
		    p[k] = r[k];
		ans = cur;
	    }	    
	}	
    }

    cout << fixed << setprecision(10) << ans << '\n';

    for (int i = 0; i < n; i++)
	cout << fixed << setprecision(10) << p[i] << ' ';

    cout << '\n';    
}

