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

const int MAXN=300;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m, d, t;
map<char, int> qtd;
string s;
set<char> j;

int main() {
  cin >> n;
  cin >> s;
  t = d = 0;
  m = -1;
  if(n%4) {
    cout << "===" << '\n';
    return 0;
  }
  qtd['A'] = qtd['G'] = qtd['C'] = qtd['T'] = qtd['?'] = 0;
  for(auto i : s) {
    qtd[i]++;
    if(i == '?')
      t++;
    else
      m = max(qtd[i], m);
  }
  for(auto e : qtd) {
    char c = e.first;
    int num = e.second;
    if(c != '?') {
      if(num < n/4)
        j.insert(c);
    }
  }
  
  if(m > n/4) {
    cout << "===" << '\n';
    return 0;
  }

  else {
    for(int i = 0; i < n; i++) {
      if(s[i] == '?') {
        s[i] = *j.begin();
        qtd[*j.begin()]++;
        if(qtd[*j.begin()] == n/4)
          j.erase(j.begin());
      }      
    }
    cout << s << '\n';
  }
}
