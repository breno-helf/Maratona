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

int n, a[MAX], b[MAX];
int diff[MAX];

int binary_search_diff(int l, int r, int val) {
   while (l < r) {
      int mid = (l + r) / 2;
      if (diff[mid] <= val)
         l = mid + 1;
      else
         r = mid;
   }

   if (diff[l] <= val)
      return r + 1;
   
   return l;
}

int main() {
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
      scanf("%d", a + i);
   for (int i = 0; i < n; i++) {
      scanf("%d", b + i);
      diff[i] = a[i] - b[i];
   }

   sort(diff, diff + n);

   ll ans = 0;
   for (int i = 0; i < n; i++) {
      int pos = binary_search_diff(i + 1, n - 1, -diff[i]);
      //      debug("--> %d\n", pos);
      ans += n - pos;      
   }

   printf("%lld\n", ans);
}
