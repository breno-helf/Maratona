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

const int MAXN=122213;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;


int p, b, a;

int main(){
  scanf("%d%d%d", &p, &a, &b);
  if(p-b<0) printf("-1\n");
  else{
    printf("%d\n", a + p - min(p-b,a));
  }
  return 0;
}



