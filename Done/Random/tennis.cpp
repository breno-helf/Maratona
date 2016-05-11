#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=512;
const int INF=0x3f3f3f3f;

int n,p,b;
int resp,t;

int main(){
  scanf("%d%d%d", &n, &b, &p);
  t=p*n;
  resp=0;
  for(unsigned int i=n;i>1;){
    int k=(1<<(31-(__builtin_clz(i))));
    debug("--> %d\n", k);
    resp+=(k/2)*(2*b+1);
    i-=k;
    i+=k/2;
  }
  printf("%d %d\n", resp, t);
  return 0;
}




