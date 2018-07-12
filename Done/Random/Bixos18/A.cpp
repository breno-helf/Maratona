//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n;
vector<pii> vote;

int main() {
    cin >> n;
    int pink = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        string s;
        cin >> s;
        vote.pb(pii(r, s == "pink"));
        pink += (s == "pink");
    }
    sort(vote.begin(), vote.end());
    reverse(vote.begin(), vote.end());
    
    for (int k = 0; k <= 4000; k++) {
        while(!vote.empty() && vote.back().first < k) {
            n--;
            pink -= vote.back().second;
            vote.pop_back();
        }
        if (2 * pink > n) {
            printf("%d\n", k);
            return 0;
        }
    }
    puts("-1");
    return 0;
}

