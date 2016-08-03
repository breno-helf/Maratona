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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int a, b, c;
int x, y, z;

int main(){
  cin >> a >> b >> c;
  cin >> x >> y >> z;
  int ca, cb, cc;
  ca = (a-x)/2;
  ca = max(ca,0);
  cb = (b-y)/2;
  cb = max(cb,0);
  cc = (c-z)/2;
  cc = max(cc,0);
  int na, nb, nc;
  na = (x-a);
  na = max(na,0);
  nb = (y-b);
  nb = max(nb,0);
  nc = (z-c);
  nc = max(nc,0);
  //debug("%d %d %d\n", ca, cb, cc);  
  //debug("%d %d %d\n", na, nb, nc);
  
  if(ca - na + cb - nb + cc - nc >= 0) puts("Yes");
  else puts("No");
  return 0;
}




