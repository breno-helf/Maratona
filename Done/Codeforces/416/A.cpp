//If you are trying to hack me I wish you can get it, Good Luck :D.
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

ll A[MAX], B[MAX], a, b;


int main() {
    cin >> a >> b;
    for (int i = 1; i < MAX; i++) {
	if (i % 2) A[(i + 1) / 2] = A[i/2] + i;
	else B[i/2] = B[i/2 - 1] + i;
    }
    
    for (int i = 0; i < MAX; i++) {
	if (A[i] > a) {
	    cout << "Vladik\n";
	    return 0;
	}
	if (B[i] > b) {
	    cout << "Valera\n";
	    return 0;
	}
    }
}
