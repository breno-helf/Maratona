#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11233;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
vector<int> ans;
void up() {
    while ((int)ans.size() >= 2) {
	if (ans[ans.size() - 1] == ans[ans.size() - 2]) {
	    int v = ans[ans.size() - 1];
	    ans.pop_back();
	    ans.pop_back();
	    ans.pb(v + 1);
	} else break;
    }
}
int main() {
    cin >> n;
    while(n--) {
	ans.pb(1);
	up();
    }

    for (auto e : ans) cout << e << ' ';
    cout << '\n';
}
