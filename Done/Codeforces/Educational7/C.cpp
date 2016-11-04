//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=512345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

set <pii> st;
int vec[MAXN];


int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&vec[i]);
  }
  int aux = 0;
  for(int i = 1; i < n; i++) {
    if(vec[i] != vec[i - 1]) {
      st.insert(mp(aux, i - 1));
      aux = i;
    }
  }
  st.insert(mp(aux, n - 1));
  for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;
    b--;
    auto it = st.upper_bound(mp(a,INF));
    it = prev(it);
    debug("%d kk\n", it->second);
    if(b<=it->second){
      if(vec[b]!=c){
	printf("%d\n",b+1);
	continue;
      }
      else{
	printf("-1\n");
	continue;
      }	
    }
    else{
      if(vec[it->second]!=c){
	printf("%d\n",it->second+1);
	continue;
      }
      else{
      
	it = next(it);
	if(it!=st.end()){
	    printf("%d\n", it->first+1);
	    continue;
	}
	else{
	  printf("-1\n");
	  continue;
	}
	//      printf("rr %d\n",it->second);


      }
    }
  }
}

