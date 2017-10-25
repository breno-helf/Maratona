//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;
int A[MAX], B[MAX];

int main() {
    cin.sync_with_stdio(false);
    cout.tie(0);
    
    cin >> s;
    int n = s.size();
    s = "#" + s;
    
    for (int i = 1; i <= n; i++) {
	A[i] += A[i - 1];
	B[i] += B[i - 1];

	A[i] += (s[i] == 'a');
	B[i] += (s[i] == 'b');
	//cout << "A[i] " << A[i] << " B[i] " << B[i] << '\n';
    }
    int resp = A[n];

    for (int i = 1; i <= n; i++) {
	for (int j = i; j <= n; j++) {
	    /*cout << n - B[i - 1]
	      - A[j] + A[i - 1] - B[n] + B[j] << " " << i << " " << j << '\n';*/
	    resp = max(resp, n - B[i - 1]
		       - A[j] + A[i - 1] - B[n] + B[j]);
	}	
    }

    cout << resp << '\n';
}

