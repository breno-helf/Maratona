#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 112345;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;


int main () {
  cin.sync_with_stdio(false);
  cin.tie(0);
  
  string s = "";

  while (true) {
    cin >> s;
    if (s == "END") break;

    int tam = s.size();
    for (int i = tam - 1; i >= 0; i--) {
      if (s[i] != '0') {
	s[i]--;
	break;
      }
    }
    cout << stoi(s) << '\n';
  }
  return 0;
  
}
