//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int t, n;
int a[MAX];

int main() {
   scanf("%d", &t);
   while (t--) {
      scanf("%d", &n);
      set<int> S;
      for (int i = 0; i < n; i++) {
         scanf("%d", a + i);
         S.insert(a[i]);
      }

      printf("%d\n", (int)S.size());
   }
}
