#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int h[MAXN],l[MAXN],n; // l de largura, a de altura atual

ll resp,a;

stack<int> pl;//Pilha --> p.top() [topo] ; p.push(x) [insere x] ;
//--> p.pop() [retira topo] ; p.empty() [informa se está vazio]
stack<int> pr;
int main(){
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    memset(h,0,sizeof(h));
    memset(l,0,sizeof(l));
    for(int i=0;i<n;i++){
      scanf("%d", &h[i]);
      l[i]=1;
    }
    resp=-1;
    while(!(pl.empty())) pl.pop();
    while(!(pr.empty())) pr.pop();
    for(int i=0;i<n;i++){
      while(!(pl.empty()) && h[i]<=h[pl.top()]) pl.pop();
      if(pl.empty()) l[i] +=i;
      else l[i]+= i-pl.top()-1;
      pl.push(i);
    }
    for(int i=n-1;i>=0;i--){
      while(!(pr.empty()) && h[i]<=h[pr.top()]) pr.pop();
      if(pr.empty()) l[i]+=n-1-i;
      else l[i]+=pr.top()-i-1;
      pr.push(i);
    }
    for(int i=0;i<n;i++){
      a=(ll)l[i]*(ll)h[i];
      resp=max(resp,a);
    }
    printf("%lld\n", resp);
  }
  return 0;
}
  



