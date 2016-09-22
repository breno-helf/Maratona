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

const int MAXN=1231;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b || b == c || c == a) puts("S");
  else if((a + b) == c || (a + c) ==  b || (b + c) == a) puts("S");
  else puts("N");
}
