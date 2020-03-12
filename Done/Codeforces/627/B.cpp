//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 5123;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

int n, a[MAX], last[MAX], t;

int main() {
   scanf("%d", &t);

   while (t--) {
      memset(last, -1, sizeof(last));
      scanf("%d", &n);
      bool ok = false;
      int cntLast = 0;
      int lastNum = -1;
      for (int i = 0; i < n; i++) {
         scanf("%d", a + i);

         if (lastNum == a[i])
            cntLast++;
         else {
            lastNum = a[i];
            cntLast = 1;
         }
         
         if (last[a[i]] != -1 && i - last[a[i]] > 1)
            ok = true;
         if (cntLast == 3)
            ok = true;
         
         
         last[a[i]] = i;       
      }

      if (ok)
         puts("YES");
      else
         puts("NO");
   }
}
