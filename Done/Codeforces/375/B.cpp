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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n;
string s;

int main() {
  cin >> n;
  cin >> s;
  int cur = 0, mx = 0;
  int pal = 0;
  bool par = false;
  
  for(int i = 0; i < n; i++) {
    if(s[i] == '_' || s[i] == '(' || s[i] == ')') {
      if(!par) mx = max(mx, cur);
      if(par && s[i] == '_') {
	if(cur) pal++;
      }
      if(s[i] == '(') par = true;
      else if(s[i] == ')') {
	if(cur) pal++;
	par = false;
      }
      cur = 0;
    }
    else cur++;   
  }
  mx = max(mx, cur);
  cout << mx << ' ' << pal << '\n';
}
