#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=4123;
const int INF=0x3f3f3f3f;

int crivo[2123456];
int p[MAXN][MAXN];
int v[MAXN],resp,n;
vector<int> g;
vector<int> a;

int main(){
  resp=0;
  scanf("%d", &n);
  for(int i=0;i<n;i++) v[i] = 1;
  for(int i=2;i*i<=2000000;i++) if(crivo[i]==0) for(int k=i*i;k<=2000000;k+=i) crivo[k]=1;
  for(int i=0;i<n-1;i++){
    for(int k=i+1;k<n;k++){
      if(!(crivo[v[i]+v[k]])) p[i][k]=p[k][i]=1;
    }
  }
  int op = 0;
  for(int i=0;i<n;i++){
    int mx=0;
    a.clear();
    a.pb(i);
    for(int k=0;k<n;k++){
      if(k!=i){
	if(p[i][k]){
	  int e=0;
	  for(int j=0;j<a.size();j++){
	    if(!p[k][a[j]]){
	      e++;
	      break;
	    }
	    op++;
	  }
	  if(e) continue;
	  else a.pb(k);
	}
      }
    }
    mx=a.size();
    if(mx>resp){
      resp=mx;
      swap(g,a);
    }
  }
  printf("%d\n", resp);
  if(resp>0) printf("%d", v[g[0]]);
  for(int i=1;i<g.size();i++) printf(" %d", v[g[i]]);
  printf("\n");
  printf("%d\n", op);
  return 0;
}

  
