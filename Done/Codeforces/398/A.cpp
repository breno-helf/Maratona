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

int n;
int top;
int seen[MAX];

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int last = n;
    for (int i = 0; i < n; i++) {
	int num;
	cin >> num;
	seen[num] = 1;
	if (num == last) {
	    int k = num;
	    while(seen[k]) {
		cout << k << ' ';
		k--;
	    }
	    cout << '\n';
	    last = k;
	} else {
	    cout << '\n';
	}
    }
    return 0;
}

