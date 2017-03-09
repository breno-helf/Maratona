//If you are trying to hack me I wish you can get it, Good Luck :D
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct point {
    int x, y;
    point (int X = 0, int Y = 0): x(X), y(Y) {}    
}s;

int n, mrk[MAX];
point p[MAX];

int main () {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s.x >> s.y;
    for (int i = 0; i < n; i++) {
	cin >> p[i].x >> p[i].y;	
    }
    int resp = 0;
    for (int i = 0; i < n; i++) {
	int dx = (s.x - p[i].x);
	int dy = (s.y - p[i].y);
	if (mrk[i]) continue;
	mrk[i] = 1;
	resp++;
	for (int j = i; j < n; j++) {
	    if (mrk[j]) continue;
	    if ((dx * (p[j].y - s.y)) == (dy * (p[j].x - s.x))) {
		mrk[j] = 1;
	    }
	}
    }
    cout << resp << '\n';
}

