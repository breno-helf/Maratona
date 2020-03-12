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

int t, dist[MAX];
string s;


int main() {
   cin >> t;

   while (t--) {
      cin >> s;
      int last = 0;
      int mx = 1;
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == 'R') {
            mx = max(mx, (i + 1) - last);
            last = i + 1;
         }
      }
      //debug("--> %d %d\n", (int)s.size() + 1, last);
      mx = max(mx, (int)s.size() + 1 - last);

      cout << mx << '\n';
   }

   return 0;
}
