//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

ll n, h, k, a[MAXN];

int main(){
  scanf("%lld%lld%lld", &n, &h, &k);

  for(int i=1;i<=n;i++){
    scanf("%lld", &a[i]);

  }
  ll smash = 0;
  int pt = 1;  
  ll t = 0;
  while(pt<=n || smash!=0){
    bool am = 0;
    while(smash+a[pt]<=h && pt<=n){
      smash+=a[pt++];
      am=1;
    }
    if(am) smash = max(0ll,smash-k), t++;
    else if(pt<=n){
      //debug("LOOP HERE\n");
      ll add = (ll)ceil((double)(smash+a[pt]-h)/(double)k);
      //debug("\n\n---> %lld\n\n", add);
      t += add;
      smash = max(0ll, smash - add*k);
    }
    else{
      //debug("DOUBLE LOOP DOUBLE FUCK YOU\n");
      ll add = (ll)ceil((double)(smash)/(double)k);
      t+= add;
      smash = 0ll;
    }
  }
  printf("%lld\n", t);
  return 0;
}
