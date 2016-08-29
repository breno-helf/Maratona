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

int bip(int n, int i) {
  if(n%2 == 0) {
    if(i%2) return (i+1)/2;
    else return (bip(n/2, i/2) + n/2);
  }
  else {
    if(i%2) return (i+1)/2;
    else {
      return (bip((n+1)/2, i/2 + 1) + (n)/2);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, i;
    scanf("%d %d", &n, &i);
    printf("%d\n", bip(n,i));
  }
  return 0;
}
