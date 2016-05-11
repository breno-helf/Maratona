#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const int cns=300;


int v[MAXN];
int l[MAXN];
int n,k,m,up,resp;

int main(){
  resp=0;
  up=0;
  scanf("%d%d%d", &n, &k, &m);
  for(int i=0;i<m;i++){
    int a;
    scanf("%d", &a);
    l[a]=i+1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
      int a;
      scanf("%d", &a);
      resp+=l[a];
      for(int i=1;i<=m;i++) if(l[i]<l[a]) l[i]++;
      l[a]=1;
    }
  }
  printf("%d\n", resp);
  return 0;
}





