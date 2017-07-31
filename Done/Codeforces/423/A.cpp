#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a, b, c;

int main() {
    int resp = 0;
    cin >> n >> a >> b;
    c = 0;
    for (int i = 0; i < n; i++) {
	int x;
	cin >> x;
	if (x == 1) {
	    if (a > 0) a--;
	    else if (b > 0) {
		b--;
		c++;
	    } else if (c > 0) {
		c--;
	    } else resp++;
	} else {
	    if (b > 0) b--;
	    else resp += 2;
	}
    }
    cout << resp << '\n';
}
