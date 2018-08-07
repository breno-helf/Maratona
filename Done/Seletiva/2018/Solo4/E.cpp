//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 11234;

int T, K, N, S;
ll D;
pii G[MAX];

vector< pair<double, int> > buildIntervals(ll k) {
    vector< pair<double, int> > I;
    
    for (int i = 1; i <= N; i++) {
        ll x = G[i].first, y = G[i].second;

        ll c = x * x + k * (k - 2LL * y) + y * y - D * D;
        ll b = - 2 * x;
        ll a = 1;

        double delta = b * b - 4 * a * c;


        
        if (delta < 0) {
            I.clear();
            return I;
        } else if (delta == 0) {
            double pos = -b / (2 * a);
            I.push_back(make_pair(pos, -i));
            I.push_back(make_pair(pos, i));
        } else {
            double left = (-b - sqrt(delta)) / (2 * a);
            double right = (-b + sqrt(delta)) / (2 * a);

            I.push_back(make_pair(left, -i));
            I.push_back(make_pair(right, i));
        }
    }

    sort(I.begin(), I.end());
    return I;
}


bool test(int k) {
    vector< pair<double, int> > I = buildIntervals(k);
    
    if (I.empty()) {
        //        printf("Circle %d - delta < 0\n", k);
        return false;
    }

    int cover = 0;
    unordered_map<int, int> mrk;
    vector<int> open;
    
    for (auto& e : I) {
        int id = e.second;
        
        if (id < 0) {
            open.push_back(-id);
        } else {
            if (mrk[id] == 1) continue;
            else {
                for (int num : open) {
                    mrk[num] = 1;
                }
                open.clear();
                cover++;
            }
        }
    }

    assert(open.empty());
    // for (auto& e : I) {
    //     double pos = e.first;
    //     int id = e.second;

    //     printf("%lf %d\n", pos, id);
        
    // }

    // printf("--------\n\n");

    // printf("I need %d soldiers to cover %d (%d)\n\n\n", cover, k, S);
    
    return cover <= S;
}



int main() {
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d %lld", &K, &N, &S, &D);

        for (int i = 1; i <= N; i++) {
            scanf("%d %d", &G[i].first, &G[i].second);
        }

        int l = - 1e9 + 10, r = K;

        while (l < r) {
            int mid = (l + r - 1) / 2;
            //printf("(%d, %d) -- %d\n", l, r, mid);
            if (test(mid)) r = mid;
            else l = mid + 1;
        }
        //printf("(%d, %d)\n", l, r);
        if (test(l) == false) printf("Case %d: IMPOSSIBLE\n", t);
        else printf("Case %d: %d\n", t, K - l);
    }
    
    return 0;
}
