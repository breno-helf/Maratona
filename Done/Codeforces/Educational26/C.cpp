#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a, b;

int x[MAX], y[MAX];
int mrk[MAX][MAX];

void deb() {
    for (int i = 1; i <= a; i++) {
	for (int j = 1; j <= b; j++) {
	    debug("%d ", mrk[i][j]);
	}
	debug("\n");
    }
    debug("------------\n\n");
}

bool pinta(int X, int Y, bool up) {
    if (X > a || Y > b) return false;

    if (up) {
	for (int i = 1; i <= Y; i++) {
	    if (mrk[X][i] == 0)
		mrk[X][i] = 1;
	    else return false;
	}
	
	for (int i = 1; i < X; i++) {
	    if (mrk[i][Y] == 0)
		mrk[i][Y] = 1;
	    else return false;
	}
	
    } else {
	for (int i = b; i >= (b - Y + 1); i--) {
	    if (mrk[a - X + 1][i] == 0)
		mrk[a - X + 1][i] = 1;
	    else return false;
	}

	for (int i = a; i > (a - X + 1); i--) {
	    if (mrk[i][b - Y + 1] == 0)
		mrk[i][b - Y + 1] = 1;
	    else return false;
	}
    }

    return true;
}

void apaga(int X, int Y, bool up) {
    if (X > a || Y > b) return;
    
    if (up) {
	for (int i = 1; i <= Y; i++) {
	    mrk[X][i] = 0;
	}
	
	for (int i = 1; i <= X; i++) {
	    mrk[i][Y] = 0;
	}
    } else {
	for (int i = b; i >= (b - Y + 1); i--) {
	    mrk[a - X + 1][i] = 0;	    
	}

	for (int i = a; i >= (a - X + 1); i--) {
	    mrk[i][b - Y + 1] = 0;
	}
    }
}

int area(int i, int j) {
    bool ok = false;
    for (int u = 0; u < 2; u++) {
	for (int v = 0; v < 2; v++) {
	    int x1, y1, x2, y2;
	    if (u == 0) {
		x1 = x[i], y1 = y[i];
	    } else {
		x1 = y[i], y1 = x[i];
	    }

	    if (v == 0) {
		x2 = x[j], y2 = y[j];
	    } else {
		x2 = y[j], y2 = x[j];
	    }
	    
	    if (pinta(x1, y1, true) == false) continue;
	    
	    if (pinta(x2, y2, false) == false) {
	
		apaga(x1, y1, true);
		apaga(x2, y2, false);
	    } else {
		apaga(x1, y1, true);
		apaga(x2, y2, false);
		ok = true;
	    }
	}
    }
    //if (ok) debug("--> %d %d %d\n", i, j, (x[i] * y[i] + x[j] * y[j]));
    if (ok) return (x[i] * y[i] + x[j] * y[j]);
    else return 0;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);

    for (int i = 1; i <= n; i++) {
	scanf("%d%d", x + i, y + i);
    }

    int resp = 0;
    
    for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	    resp = max(resp, area(i, j));

    printf("%d\n", resp);
}

