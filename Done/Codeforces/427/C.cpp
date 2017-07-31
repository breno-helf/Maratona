#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct star {
    int x, y, s;
    star(int X = 0, int Y = 0, int S = 0): x(X), y(Y), s(S) {}
};

int n, q, c;
star v[MAX];

int bit[112][112][12];


void up(int x, int yy, int b, int val) {
    for (; x <= 100; x += (x&-x))
	for (int y = yy; y <= 100; y += (y&-y))
	    bit[x][y][b] += val;
}

int get(int x, int yy, int b) {
    int sum = 0;
    for (; x > 0; x -= x&-x)
	for (int y = yy; y > 0; y -= y&-y)
	    sum += bit[x][y][b];
    return sum;
}

void build() {
    for (int i = 0; i < n; i++) {
	up(v[i].x, v[i].y, v[i].s, 1);
    }
}

struct query {
    int x1, x2, y1, y2, t, id;
    query(int X1 = 0, int Y1 = 0, int X2 = 0, int Y2 = 0, int T = 0, int ID = 0) {
	x1 = X1;
	y1 = Y1;
	x2 = X2;
	y2 = Y2;
	t = T;
	id = ID;
    }
    bool operator < (const query ot) const {
	return t < ot.t;
    }
};

vector<query> Q;
int ans[MAX];

int main() {
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++) {
	int A, B, C;
	cin >> A >> B >> C;
	v[i] = star(A, B, C);
    }

    build();
    
    for (int i = 0; i < q; i++) {
	int x1, x2, y1, y2, t;
	cin >> t >> x1 >> y1 >> x2 >> y2;


	t = t % (c + 1);
	
	int resp = 0;
	for (int k = 0; k <= c; k++) {
	    
	    resp += (max(get(x2, y2, k) - get(x1 - 1, y2, k) - get(x2, y1 - 1, k) + get(x1 - 1, y1 - 1, k), 0)) * ((k + t) % (c + 1));
	}

	cout << resp << '\n';
	
	//Q.pb(query(x1, y1, x2, y2, t, i));
    }
    
    // debug("--> %d\n", get(2, 2, 1));
    
    // sort(Q.begin(), Q.end());
    // for (int i = 0; i < q; i++) {
    // 	int add = Q[i].t;
    // 	add %= (c + 1);
    // 	int resp = 0;
    // 	for (int k = 0; k <= c; k++) {
    // 	    resp += (get(Q[i].x2, Q[i].y2, k) - get(Q[i].x1, Q[i].y1, k)) * ((k + add) % (c + 1));
    // 	}
    // 	ans[Q[i].id] = resp;	
    // }

    // for (int i = 0; i < q; i++) cout << ans[i] << '\n';
    return 0;
}
