//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 123121;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

ll u, v;

bool can_it_fit(ll a, ll b) {
   int qtdA = __builtin_popcountll(a);
   int qtdB = __builtin_popcountll(b);
   ll sum = a + b;
   if (__builtin_popcountll(sum) == (qtdA + qtdB)) return true;

   return false;
}

int main() {
   scanf("%lld %lld", &u, &v);
   if (u > v) {
      puts("-1");
      return 0;
   }

   ll d = v - u;

   if (d == 0) {
      if (v == 0)
         printf("%d\n", 0);
      else
         printf("%d\n%lld\n", 1, u);
   } else {
      ll p = d/2;
      if (d % 2 == 0) {
         if(can_it_fit(p, u))
            printf("%d\n%lld %lld\n", 2, u + p, p);
         else
            printf("%d\n%lld %lld %lld\n", 3, u, p, p);
      } else {
         puts("-1");
      }
   }
}

