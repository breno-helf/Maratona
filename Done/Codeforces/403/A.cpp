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

set<int> s;
int n;
int ans;

int main () {
    ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
	int x;
	scanf("%d", &x);
	if (s.find(x) != s.end())
	    s.erase(x);
	else
	    s.insert(x);
	ans = max(ans, (int)s.size());
    }
    printf("%d\n", ans);
}

