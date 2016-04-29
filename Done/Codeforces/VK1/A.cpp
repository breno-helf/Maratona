#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

int p[MAXN],t[MAXN],c,n,pl,pr,tl,tr;

char l[20]="Limak",r[20]="Radewoosh",e[10]="Tie";

int main(){
  scanf("%d%d", &n, &c);
  for(int i=1;i<=n;i++) scanf("%d", &p[i]);
  for(int i=1;i<=n;i++) scanf("%d", &t[i]);
  pr=pl=0;
  tl=tr=0;
  for(int i=1;i<=n;i++){
    tl+=t[i];
    pl+=max(0,p[i]-c*tl);
  }
  for(int i=n;i>0;i--){
    tr+=t[i];
    pr+=max(0,p[i]-c*tr);
  }
  if(pl==pr){
    printf("%s\n", e);
    return 0;
  }
  pl>pr ? printf("%s\n", l) : printf("%s\n", r);
  return 0;
}



