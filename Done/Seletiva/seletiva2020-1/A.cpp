//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1312;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

string s;


int main() {
   cin >> s;
   int a = INF, z = -1;

   for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A') a = min(a, i);
      if (s[i] == 'Z') z = max(z, i);      
   }

   cout << z - a + 1 << endl;
}
