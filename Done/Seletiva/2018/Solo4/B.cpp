//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 212345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
string S, T;
set< pair<char, int> > C[30];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> S >> T;

    int dist = 0;
    int fixed = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) {
            dist++;
            C[S[i] - 'a'].insert(make_pair(T[i], i));
        }
    }
    fixed = dist;
    int A = -2, B = -2;
    
    for (int i = 0; i < n; i++) {
        if (S[i] != T[i]) {
            if (!C[T[i] - 'a'].empty()) {
                if (fixed - 1 < dist) {
                    dist = min(dist, fixed - 1);
                    A = i;
                    auto it = C[T[i] - 'a'].begin();
                    B = it->second;
                }
                
                auto it = C[T[i] - 'a'].lower_bound(make_pair(S[i], -1));

                if (it == C[T[i] - 'a'].end())
                    continue;

                if (it->first == S[i]) {
                    if (fixed - 2 < dist) {
                        dist = min(dist, fixed - 2);
                        A = i;
                        B = it->second;
                    }
                }
            }
        }
    }

    cout << dist << '\n';
    cout << A + 1 << ' ' << B + 1 << '\n';
    return 0;
}
