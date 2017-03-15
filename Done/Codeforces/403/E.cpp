//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct op {
    string a, x, b;
    op(string A = "", string X = "", string B = ""): a(A), x(X), b(B) {}
};

int n, m, pre[MAX][2];
bool num[MAX];
string s[MAX], r[MAX];
map<string, bool> var;
map<string, int> id;
op calc[MAX];
string mn, mx;

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TROXA = 1;
    var["?"] = true;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
	string v;
	cin >> s[i] >> v;
	id[s[i]] = i;
	cin >> v;
	if (var.find(v) != var.end()) {
	    string x, b;
	    cin >> x >> b;
	    calc[i] = op(v, x, b);
	    num[i] = false;
	    var[s[i]] = true;
	} else {
	    r[i] = v;
	    var[s[i]] = true;
	    num[i] = true;
	}
    }
    mn = mx = "";
    
    for (int k = 0; k < m; k++) {
	int resp0, resp1;
	resp0 = resp1 = 0;
	for (int i = 0; i < n; i++) {
	    if (num[i]) {
		if (r[i][k] == '1') {
		    resp0++;
		    resp1++;
		    pre[i][0] = 1;
		    pre[i][1] = 1;
		} else {
		    pre[i][0] = pre[i][1] = 0;
		}
	    } else {		
		int a = (calc[i].a == "?") ? 0 : pre[id[calc[i].a]][0];
		int b = (calc[i].b == "?") ? 0 : pre[id[calc[i].b]][0];

		if (calc[i].x == "AND")
		    pre[i][0] = a & b;
		else if (calc[i].x == "OR")
		    pre[i][0] = a | b;
		else
		    pre[i][0] = a ^ b;
		if (pre[i][0]) resp0++;

		a = (calc[i].a == "?") ? 1 : pre[id[calc[i].a]][1];
		b = (calc[i].b == "?") ? 1 : pre[id[calc[i].b]][1];
		if (calc[i].x == "AND")
		    pre[i][1] = a & b;
		else if (calc[i].x == "OR")
		    pre[i][1] = a | b;
		else
		    pre[i][1] = a ^ b;
		if (pre[i][1]) resp1++;			
	    }
	    debug("%d > %d %d\n", i, pre[i][0], pre[i][1]);
	}
	debug("\n-- %d %d\n", resp0, resp1);
	if (resp1 > resp0) {
	    mx += "1";
	    mn += "0";
	} else if (resp1 < resp0){
	    mx += "0";
	    mn += "1";
	} else {
	    mx += "0";
	    mn += "0";
	}
    }
    cout << mn << '\n' << mx << '\n';
    return 0;
}
