//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll n, k, sum[MAX];
pll op[MAX];



int main() {
   scanf("%lld%lld", &n, &k);
   for (int i = 0; i < n; i++) {
      ll a, b;
      scanf("%lld%lld", &a, &b);
      op[i] = pii(a, b);
   }
   sort(op, op + n);
   for (int i = 0; i < n; i++) {
      sum[i] = op[i].second;
      if (i > 0) sum[i] += sum[i - 1];      
   }

   ll l = 0, r = n - 1;

   while (l < r) {
      ll mid = (l + r) / 2;
      //debug("--> mid = %lld and sum[mid] = %lld\n", mid, sum[mid]);
      if (sum[mid] < k) l = mid + 1;
      else r = mid;
   }

   printf("%lld\n", op[l].first);

   return 0;
}
