#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int n,bit[MAXN],v[MAXN],resp;

void up(int x, int val){
  for(int k=x;k<=n;k+=(k&-k)) bit[k]+=val;
}

int query(int x){
  int ret=0;
  for(int k=x;k>0;k-=(k&-k)) ret+=bit[k];
  return ret;
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &v[i]);
  }
  for(int i=n;i>=1;i--){
    resp+=query(v[i]);
    up(v[i],1);
  }
  printf("%d\n", resp);
  return 0;
}
	   



