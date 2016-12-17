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

const int MAXN=100;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

set<string> s;
string ini, c;
int main() {
  cin >> c;
  for(int i = 0; i < c.size(); i++) {
    char aux = c[0];
    s.insert(c);
    for(int j = 1; j < c.size(); j++)
      c[j-1] = c[j];
    c[c.size() - 1] = aux;
  }
  cout << s.size() << endl;


}
