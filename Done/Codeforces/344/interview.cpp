#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

int n, a[MAXN], b[MAXN]
ll resp;

int main(){
  resp=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%d", a[i]);
  for(int i=0;i<n;i++) scanf("%d", b[i]);
  for(int i=0;i<n;i++){
    ll atual=0;
    for(int k=i;k<n;k++){
      atual|=a[k];
      resp=max(resp,atual);
    }
  }
  printf("%lld", resp);
  return 0;
}
