//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double INF = 1e9;

int n;
vector<pii> I;

bool solveL(int bm, double dist, double L) {
    if (bm == ((1<<(int)I.size()) - 1)) return true;

    for (int i = 0; i < I.size(); i++) {
        if ((bm & (1<<i)) == 0) {
            double l = L + dist;
            l = max(l, (double)I[i].first);
            if (l <= I[i].second) {
                if (solveL(bm | (1<<i), dist, l)) return true;
            }
        }
    }

    return false;
}

bool solveR(int bm, double dist, double R) {
    if (bm == ((1<<(int)I.size()) - 1)) return true;

    for (int i = 0; i < I.size(); i++) {
        if ((bm & (1<<i)) == 0) {
            double r = R - dist;
            r = min(r, (double)I[i].second);
            if (r >= I[i].first) {
                if (solveR(bm | (1<<i), dist, r)) return true;
            }
        }
    }

    return false;
}

bool test(double dist) {
    return solveR(0, dist, INF) || solveL(0, dist, -INF);
}

int convertSec(double min) {
    double sec = min * 60;
    int ans = round(sec);

    return ans;
}

int main() {
    int T = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        I.clear();
        
        for (int i = 0; i < n; i++) {
            int L, R;
            scanf("%d%d", &L, &R);

            I.pb(pii(L, R));
        }

        sort(I.begin(), I.end());

        double L = 0, R = 1440;
        for (int it = 0; it < 100; it++) {
            double M = (L + R) / 2;
            if (test(M)) {
                L = M;
            } else {
                R = M;
            }
        }
        
        int min = L;
        int sec = convertSec(L - min);
        if (sec == 60) {
            min++;
            sec = 0;
        }
        printf("Case %d: %d:%02d\n", T++, min, sec);
    }

    return 0;
}


