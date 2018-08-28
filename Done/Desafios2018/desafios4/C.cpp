//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii, int> triple;
typedef pair<ll,ll> pll;

struct event {
    int pos, id;
    event(int P, int I):
        pos(P), id(I) {}

    bool operator < (const event ot) const {
        if (pos != ot.pos) return (pos < ot.pos);
        return (id < ot.id);
    }
};

int n;
vector<event> E;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        E.push_back(event(l, -i));
        E.push_back(event(r, i));
    }
    sort(E.begin(), E.end());
    
    map<int, int> important;
    set<int> open;
    int last = -1;
    for (int i = 0; i < (int)E.size(); i++) {
        event e = E[i];
        // debug("Analizing (%d, %d) - last %d\n", e.id, e.pos, last);
        // debug("Our open set is: ");
        // for (int num : open) {
        //     debug("%d ", num);
        // }
        // debug("\n\n");
        
        if (open.size() == 1) {
            // debug("Came here with when analizing %d with %d on set\n", e.id, *open.begin());
            // debug("e.pos %d -- last %d\n\n", e.pos, last);
            if (e.pos - last > 1) {
                // debug("%d is important\n", *open.begin());
                important[ *open.begin() ] = 1;
            }
        }
            
        if (e.id < 0) {                        
            open.insert(-e.id);
            if (open.size() == 1 && (E[i + 1].pos > e.pos || -E[i + 1].id == e.id)) {
                // debug("%d is important\n", -e.id);
                important[-e.id] = 1;
            }
        } else {
            if (open.size() == 1 && (E[i - 1].pos < e.pos || -E[i + 1].id == e.id)) {
                important[e.id] = 1;
                // debug("%d is important\n", -e.id);

            }
            if (important[e.id] == 0) {
                printf("%d\n", e.id);
                return 0;
            }
            
            open.erase(e.id);
        }
              
        last = e.pos;
    }
    
    puts("-1");
    return 0;
}

