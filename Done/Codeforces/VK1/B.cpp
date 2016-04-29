#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=212345;
const int INF=0x3f3f3f3f;

int n,q,k,t[MAXN];

set<int> on;


int main(){
  scanf("%d%d%d", &n, &k, &q);
  for(int i=0;i<n;i++) scanf("%d", &t[i]);
  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d%d", &a, &b);
    if(a==1){
      on.insert(t[b-1]);
      if((on.size())>k){
	int e=*(on.begin());
	debug("Apaguei %d\n", e);
	on.erase(e);
      }
    }
    else{
      if((on.find(t[b-1]))==(on.end())) printf("NO\n");
      else printf("YES\n");
    }
  }
  return 0;
}


