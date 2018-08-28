//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e4 + 100;
const int LIM = 1e4 + 10;
const int INF = 0x3f3f3f3f;

struct point {
    int x, y, id;

    point(int X = 0, int Y = 0, int ID = -1):
        x(X), y(Y), id(ID) {}

    bool operator < (const point ot) const {
        if (x != ot.x) return x < ot.x;
        if (y != ot.y) return y < ot.y;
        return id < ot.id;
    }  
};


int seg[4 * MAX];
vector<int> ans;
vector<point> P;
int n;

void update(int no, int l, int r, int pos, int val) {
    if (l == r) {
        seg[no] = max(seg[no], val);
        return;
    }
    
    int mid = (l + r) / 2;
    int E = 2 * no;
    int D = E + 1;
    if (pos <= mid) update(E, l, mid, pos, val);
    else update(D, mid + 1, r, pos, val);

    seg[no] = max(seg[E], seg[D]);
}

int query(int no, int l, int r, int lo, int hi) {
    if (lo > r || hi < r) return -INF;
    if (lo >= l && r <= hi) return seg[no];

    int E = 2 * no;
    int D = E + 1;

    int mid = (l + r) / 2;

    return max(query(E, l, mid, lo, hi), query(D, mid + 1, r, lo, hi));
}


int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        P.push_back(point(x, y, i));
    }

    sort(P.begin(), P.end());
    reverse(P.begin(), P.end());

    
    for (int i = 0; i < n; i++) {
        int Q = query(1, 1, LIM, P[i].x, MAX);

        //printf("Analisando ponto %d %d -- Max eh %d\n", P[i].x, P[i].y, Q);
        
        if (Q < P[i].y) ans.push_back(P[i].id + 1);

        update(1, 1, LIM, P[i].x, P[i].y);        
    }

    sort(ans.begin(), ans.end());
    
    for (int num : ans) {
        printf("%d ", num);
    }

    printf("\n");

    return 0;
}
