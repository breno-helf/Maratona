#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

//const int MAXN=
const int INF=0x3f3f3f3f;

int n,resp,d;

int main(){
  resp=0;
  d=1;
  scanf("%d", &n);
  while(n>0){
    n-=d;
    if(n<0) break;
    resp++;
    if(d==1) d=2;
    else d=1;
  }
  printf("%d\n", resp);
  return 0;
}

