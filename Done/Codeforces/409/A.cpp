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

string s;
int cnt = 0, V = 0, K = 0;
int n;
int main() {
    cin >> s;
    n = s.size();
    for (int i = 1; i < n; i++) {
	if (s[i] == 'K' && s[i - 1] == 'V') {
	    cnt++;
	    i++;
	} else if (s[i] == 'K' && s[i - 1] == 'K') {
	    K = 1;
	}
    }

    for (int i = (n - 1); i >= 1; i--) {
	if (s[i] == 'K' && s[i - 1] == 'V') i--;
	else if (s[i] == 'V' && s[i - 1] == 'V') V = 1;
    }

    //debug("--> %d %d %d\n", cnt, V, K);
    if (V == 1 || K == 1) cnt++;
    printf("%d\n", cnt);
    
}

