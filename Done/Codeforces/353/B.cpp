//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1243;
const int INF=0x3f3f3f3f;


int n, a, b, c, d;
ll cnt = 0;
ll resp;

bool chk(int x){
  if(x>=1 && x<=n) return 1;
  return 0;
}

int main(){
  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  for(int i=1;i<=n;i++){
    if( chk(i-c+b) && chk(i-d+a) && chk(i-c-d+a+b) ) cnt++;
  }
  printf("%I64d\n", (ll)(n)*(cnt));
  return 0;
}


