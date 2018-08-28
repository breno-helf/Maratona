//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
vector<pii> s;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int v;
        scanf("%d", &v);
        s.pb(pii(v, i));
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());

    deque<pii> test;
    test.push_back(s[0]);
    for (int j = 1; j <= n; j++) {
        int i = j % n;
        
        int T = s[i].first;
        
        //printf("==> Trying to clean %d {%d}\n", s[i].second, s[i].first);
        while (T > 0) {
            pii e = test.front();
            test.pop_front();

            //printf("[%d] - %d is in top of stack with %d exams {%d}\n", s[i].second, e.second, e.first, T);
            
            if (e.second == s[i].second) {
                puts("impossible");
                return 0;
            }
            
            if (e.first >= T) {
                e.first -= T;
                T = 0;
            } else {
                T -= e.first;
                e.first = 0;
            }
            
            if (e.first > 0) test.push_front(e);
        }

        if (T > 0) {
            puts("impossible");
            return 0;
        }

        if (i != 0)
            test.push_back(s[i]);
    }
    // while (!test.empty()) {
    //     pii e = test.front();
    //     test.pop_front();

    //     printf("--> %d %d\n", e.first, e.second);
    // }
    
    if (!test.empty()) {
        puts("impossible");
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", s[i].second);
    }
    printf("\n");
}
