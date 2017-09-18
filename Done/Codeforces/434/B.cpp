//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, m;
int pos[MAX];

bool test(int st, int k) {
    int cnt = 0;
    int f = st;
    for (int i = 1; i <= 100; i++) {
	if (pos[i] != -1 && pos[i] != f) return false;
	cnt++;
	if (cnt == k) {
	    cnt = 0;
	    f++;
	}
    }
    return true;
}

int calc(int st, int num, int k) {
    int cnt = 0;
    int f = st;
    for (int i = 1; i < num; i++) {
	cnt++;
	if (cnt == k) {
	    cnt = 0;
	    f++;
	}	
    }
    return f;
}

int main() {
    memset(pos, -1, sizeof(pos));
    scanf("%d%d", &n, &m);
    int mn = INF;
    for (int i = 0; i < m; i++) {
	int a, b;
	scanf("%d%d", &a, &b);
	pos[a] = b;
	mn = min(mn, a);
    }
    
    int resp = -1;

    mn = 1;

    for (int st = 1; st <= mn; st++) {
	for (int k = 1; k <= 100; k++) {
	    if (test(st, k)) {
		int cur = calc(st, n, k);
		if (resp == -1) resp = cur;
		else if (resp != cur) {
		    puts("-1");
		    return 0;
		}
	    }
	}
    }

    printf("%d\n", resp);
}

