#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

int v[MAXN],mx[MAXN],n,k;
int num[MAXN];
//deque<int> deq;
set<int> s;
set<int>::iterator it;

int main(){
  int tam=1;
  //  memset(mx,-1,sizeof(mx));
  memset(num,0,sizeof(num));
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    scanf("%d", &v[i]);
    //  deq.pb(v[i]);
  }
  scanf("%d", &k);
  for(int i=1;i<=n;i++){
    if(!num[v[i]]){
      debug("Inseri %d\n", v[i]);
      s.insert(v[i]);
    }
    num[v[i]]++;
    if(i==k){
      it=s.end();
      --it;
      mx[0]=*it;
    }
    if(i>k){
      if(num[v[i-k]]==1){
	debug("Apaguei %d\n", v[i-k]);
	s.erase(v[i-k]);
      }
      num[v[i-k]]--;
      it=s.end();
      --it;
      mx[i-k]=*it;
      tam++;
    }
  }
  printf("%d", mx[0]);
  for(int i=1;i<tam;i++) printf(" %d", mx[i]);
  printf("\n");
  return 0;
}



