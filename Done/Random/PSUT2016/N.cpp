//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 512;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int R, C, mrk[MAX][MAX];
int g[MAX][MAX], w[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct pos {
    int h, x, y;
    pos(int H, int X, int Y): h(H), x(X), y(Y) {}
    bool operator < (const pos ot) const {
	return h > ot.h;
    }
};

bool test(int i, int j) {
    return (i >= 1 && i <= R && j >= 1 && j <= C);
}

void init(priority_queue<pos>& Q) {
    memset(w, INF, sizeof(w));
    memset(mrk, 0, sizeof(mrk));
    for (int i = 1; i <= R; i++) {
	w[i][C] = w[i][1] = 0;
	mrk[i][C] = mrk[i][1] = 1;
	Q.push(pos(g[i][C], i, C));
	Q.push(pos(g[i][1], i, 1));
    }
    
    for (int j = 1; j <= C; j++) {
	w[R][j] = w[1][j] = 0;
	mrk[R][j] = mrk[1][j] = 1;
	Q.push(pos(g[R][j], R, j));
	Q.push(pos(g[1][j], 1, j));
    }
}

void escoa() {
    priority_queue<pos> Q;
    init(Q);

    while(!Q.empty()) {
	pos cur = Q.top();
	Q.pop();
	for (int k = 0; k < 4; k++) {
	    int x = cur.x + dx[k];
	    int y = cur.y + dy[k];
	    if (test(x, y) && !mrk[x][y]) {
		w[x][y] = min(w[x][y], max(0, cur.h - g[x][y]));
		mrk[x][y] = 1;
		Q.push(pos(g[x][y] + w[x][y], x, y));
	    }
	}
    }
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; i++) {
	for (int j = 1; j <= C; j++) {
	    scanf("%d", &g[i][j]);
	}
    }
    
    escoa();
    
    ll resp = 0;

    for (int i = 1; i <= R; i++) {
	for (int j = 1; j <= C; j++) {
	    resp += (ll)w[i][j];
	}
    }

    printf("%lld\n", resp);

    return 0;
}

