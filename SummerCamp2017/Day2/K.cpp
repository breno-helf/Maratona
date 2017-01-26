#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef tuple<int,int,int> t3;
typedef pair<pii,pii> pp;
const int MAXN = 50002 * 2;

int n;
int uf[2][MAXN];

void init() {
    for (int i = 0; i < MAXN; i++)
        uf[0][i] = uf[1][i] = i;
}

int get(int a, int t) {
    if (uf[t][a] == a) return a;
    else return uf[t][a] = get(uf[t][a], t);
}

bool join(int a, int b, int t) {
    if (a == b) return true;
    //if (t)
    //    printf("joining floor %d and %d ",a,b);
    //else
    //    printf("joining up %d and %d ", a, b);


    a = get(a, t); b = get(b, t);
    //printf("get: %d %d\n", a, b);
    if (a == b) return false;
    else {
        uf[t][b] = a;
        return true;
    }
}

int ix1 = 0, ix2 = 0;
map<t3, int> m1;
map<pii, int> m2;
set<pp> s3;

int code(t3 a) {
    if (m1[a] == 0) {
        return m1[a] = ++ix1;
    } else {
        return m1[a];
    }
}

int code(pii a) {
    if (m2[a] == 0) {
        return m2[a] = ++ix2;
    } else {
        return m2[a];
    }
}

bool test(pp a) {
    if (a.first > a.second) swap(a.first, a.second);
    if (s3.find(a) == s3.end()) {
        s3.insert(a);
        return false;
    } else {
        return true;
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);

    bool ans1 = 1, ans2 = 1;

    for (int i = 0; i < n; i++) {
        int x[2], y[2], z[2];
        scanf("%d %d %d %d %d %d", &x[0], &y[0], &z[0], &x[1], &y[1], &z[1]);
        t3 a(x[0], y[0], z[0]), b(x[1], y[1], z[1]);
        pii ap(x[0], y[0]), bp(x[1], y[1]);

        if (!join(code(a), code(b), 0)) {
            ans1 = false;
        }

        if (!test(pp(ap, bp))) {
            if (!join(code(ap), code(bp), 1)) {
                ans2 = false;
            }
        }
    }

    if (ans1) {
        printf("No t");
    } else {
        printf("T");
    }
    printf("rue closed chains\n");

    if (ans2) {
        printf("No f");
    } else {
        printf("F");
    }
    printf("loor closed chains\n");
}
