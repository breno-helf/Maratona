#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=512345;
const int INF=0x3f3f3f3f;

int v[MAXN],p[MAXN];
ll ac[MAXN],bc[MAXN],resp;
int n;
char s[MAXN];


int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%d", &v[i]);
    ac[i]+=v[i];
    if(i>0) ac[i]+=ac[i-1];
  }
  scanf("%s", s);
  for(int i=0;i<n;i++){
    if(s[i]=='B'){
      bc[i]+=v[i];
      p[i]=1;
    }
    if(i>0) bc[i]+=bc[i-1];
  }
  resp=bc[n-1];
  //  debug("--> %lld\n", resp);
  for(int i=0;i<n;i++){
    ll atual=0;
    atual+=ac[i]-bc[i];
    atual+=bc[n-1]-bc[i];
    resp=max(resp,atual);
  }
  for(int i=n-1;i>0;i--){
    ll atual=0;
    atual+=ac[n-1]-ac[i-1]-bc[n-1]+bc[i-1];
    atual+=bc[i-1];
    resp=max(resp,atual);
    }
  printf("%I64d\n", resp);
  return 0;
}


