#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int val[MAXN];
int n,m,k;
int l[MAXN],c[MAXN];

int main(){
  scanf("%d%d%d", &n, &m, &k);
  for(int i=1;i<=k;i++){
    int x,y,z;
    scanf("%d%d%d", &x, &y, &z);
    val[i]=z;
    if(x==1) l[y]=i;
    else c[y]=i;
  }
  for(int i=1;i<=n;i++){
    printf("%d", val[max(l[i],c[1])]);
    for(int k=2;k<=m;k++){
      printf(" %d", val[max(l[i],c[k])]);
    }
    printf("\n");
  }
  return 0;
}



