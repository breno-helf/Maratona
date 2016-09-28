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

const int MAXN=12212;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int a, b, c, d;
int resp;
set<int> s;

int main() {
  resp = -1;
  cin >> a >> b >> c >> d;
  s.insert(1);
  for(int i = 2; i*i <= c; i++) {
    if(!(c%i)) {
      s.insert(i);
      s.insert(c/i);
    }
  }
  s.insert(c);
  for(auto e : s)
    if(!(e%a) && (e%b) && (d%e)) {
      resp = e;
      break;
    }
    
  printf("%d\n", resp);
}

