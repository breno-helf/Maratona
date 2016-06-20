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

const int MAXN=123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int c[MAXN], resp, mx;

int main(){
  for(int i=0;i<5;i++){
    int a;
    scanf("%d", &a);
    c[a]++;
    resp += a;
  }
  for(int i=1;i<=100;i++){
    if(c[i]>=2){
      mx = max(mx, i*(min(3,c[i])));
    }
  }
  printf("%d\n", resp - mx);
  return 0;
}
    


