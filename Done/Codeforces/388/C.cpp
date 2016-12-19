//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=212345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n;
string s;
set< pair<int, char> > v;
vector< pair<int, char> > el;
int d, r, ed, er;
int main() {
  int tam;
  d = r = 0;
  ed = er = 0;
  cin >> n;
  cin >> s;
  tam = s.size();
  for(int i = 0; i < tam; i++) {
    v.insert(mp(i, s[i]));
    if(s[i] == 'D')
      d++;
    else
      r++;
  }

  while(r > 0 && d > 0) {
    for(auto e : v) {
      if(e.second == 'D') {
        if(ed) {
          ed--;
          d--;
          el.pb(e);
        }
        else {
          er++;
        }
      }
      else {
        if(er) {
          er--;
          r--;
          el.pb(e);
        }
        else {
          ed++;
        }
      }
    }
    for(auto e : el)
      v.erase(e);
  }
  if(!r)
    puts("D");
  else
    puts("R");
}



