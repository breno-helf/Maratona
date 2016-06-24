//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=8123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n, m, resp;

char num[MAXN][2];

char bn[MAXN], bm[MAXN];

int dig(ll x){
  if(x<7) return 1;
  else return (1 + dig(x/7));
}

ll fat(ll x){
  if(x==0 || x==1) return 1;
  else return x*fat(x-1);
}

void tt(ll k, int q){
  int tam = dig(k);
  while( (k/7)>0 ){
    num[tam--][q] = k%7 + '0';
    k/=7;
  }
}

int main(){
  cin >> n >> m;
  int dn = dig(n-1);
  int dm = dig(m-1);
  resp = 0;
  if( (dn + dm) > 7) resp = 0;
  else{
    debug("HELLO\n");
    //tt(n,0);
    //tt(m,1);
    for(int i=0;i<=dn + dm;i++) bn[i] = bm[i] = '0';
    for(int i=0;i<n;i++){
      debug("%s\n", bn);
      for(int k=0;k<=dm;k++) bm[k] = '0';
      for(int j=0;j<m;j++){
	int e = 1;
	set<char> s;
	s.clear();
	for(int k=1;k<=dm;k++){
	  if(s.find(bm[k]) != s.end()) e = 0;
	  else s.insert(bm[k]);
	}
	for(int k=1;k<=dn;k++){
	  if(s.find(bn[k]) != s.end()) e = 0;
	  else s.insert(bn[k]);
	}
	if(e) resp++;
	bm[dm] += 1;
	for(int k = dm;k>0;k--){
	  if(bm[k]=='7'){
	    bm[k] = '0';
	    bm[k-1] += 1;
	  }
	}
      }
      bn[dn] += 1;
      for(int k=dn;k>0;k--){
	if(bn[k]=='7'){
	  bn[k] = '0';
	  bn[k-1] += 1;
	}
      }
    }
  }
  cout << resp << endl;
}
  


