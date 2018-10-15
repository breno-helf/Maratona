#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;

struct eng {
    int a, b, c;

    eng(int A = 0, int B = 0, int C = 0):
        a(A), b(B), c(C) {}

    bool operator < (const eng ot) const {
        if (a != ot.a) return (a < ot.a);
        else if (b != ot.b) return (b < ot.b);
        return (c < ot.c);
    }    
};

int n;
int seg[4 * MAX];
eng E[MAX];
int T;

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = INF;
        return;
    }

    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;

    build(esq, l, mid);
    build(dir, mid + 1, r);

    seg[id] = min(seg[esq], seg[dir]);
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;

    if (l == r) {
        seg[id] = val;
        return;
    }
    
    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;

    if (pos <= mid)
        update(esq, l, mid, pos, val);
    else
        update(dir, mid + 1, r, pos, val);

    seg[id] = min(seg[esq], seg[dir]);
}

int query(int id, int l, int r, int lo, int hi) {
    if (hi < l || lo > r) return INF;

    if (l >= lo && r <= hi) return seg[id];

    int esq = 2 * id;
    int dir = 2 * id + 1;
    int mid = (l + r) / 2;

    return min(query(esq, l, mid, lo, hi), query(dir, mid + 1, r, lo, hi));    
}


int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            E[i] = eng(a, b, c);
        }

        sort(E + 1, E + n + 1);

        build(1, 1, n);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (query(1, 1, n, 1, E[i].b) > E[i].c) ans++;

            update(1, 1, n, E[i].b, E[i].c);
        }

        printf("%d\n", ans);
    }    
}
