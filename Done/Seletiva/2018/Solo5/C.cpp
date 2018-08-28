//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 2e5 + 10;
const int INF = 0x3f3f3f3f;

int Z;
int n;
int seg[4 * MAX];
pii num[MAX];
int st[MAX];
int t[MAX];

void build(int no, int l, int r) {
    if (l == r) {
        seg[no] = st[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * no, l, mid);
    build(2 * no + 1, mid + 1, r);
    seg[no] = max(seg[2 * no], seg[2 * no + 1]);
}

void update(int no, int l, int r, int pos, int val) {
    if (l == r) {
        seg[no] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * no, l, mid, pos, val);
    else
        update(2 * no + 1, mid + 1, r, pos, val);

    seg[no] = max(seg[2 * no], seg[2 * no + 1]);
}

int query(int no, int l, int r, int lo, int hi) {
    if (r < lo || l > hi) return -1;
    if (l >= lo && r <= hi) return seg[no];

    int mid = (l + r) / 2;
     
    return max(query(2 * no, l, mid, lo, hi), query(2 * no + 1, mid + 1, r, lo, hi));
}

int main() {
    scanf("%d", &Z);
    while (Z--) {
        scanf("%d", &n);
        if (n == 0) {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", t + i);
            num[i] = pii(t[i], i);
        }
        sort(num + 1, num + 1 + n);
        unordered_map<int, int> ID;
        
        for (int i = 1; i <= n; i++) {
            ID[num[i].second] = i;
        }

        int last = INF, sz = 0;
        for (int i = n; i >= 1; i--) {
            if (t[i] < last) {
                sz++;
            } else {
                sz = 1;
            }
            last = t[i];
            st[ID[i]] = sz;
        }

        build(1, 1, n);
        
        // for (int i = 1; i <= n; i++) {
        //     debug("[%d] ", ID[i]);
        // }
        // debug("\n\n");
        
        last = -1;
        sz = 0;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (t[i] > last) {
                sz++;
            } else sz = 1;
            last = t[i];

            int l = upper_bound(num + 1, num + 1 + n, pii(t[i], n + 1)) - num;
            //debug("[%d](%d, %d) ", l, num[l].first, num[l].second);
            if (l > n) ans = max(ans, sz);
            else ans = max(ans, sz + query(1, 1, n, l, n));
            update(1, 1, n, ID[i], 0);
        }
        //debug("\n\n");
        
        printf("%d\n", ans);
    }
    
    return 0;
}
