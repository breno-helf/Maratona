#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int MAXB=40;
const int INF=0x3f3f3f3f;


ll a,sub;
ll resp;

int main(){
  scanf("%I64d", &a);
  sub=0;
  if(a>=13) sub=100*(1ll<<(a-13));
  resp=(1ll<<a);
  resp-=sub;
  printf("%I64d\n", resp);
  return 0;
}





