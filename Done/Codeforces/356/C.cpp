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

const int MAXN=112;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

vector<int> p;

int crivo[MAXN], d;

string res;

int main(){
  for(int i=2;i<11;i++) if(!crivo[i]) for(int k=i;k*i<=100;k++) crivo[k*i] = i;
  for(int i=2;i<=100;i++){
    if(!crivo[i]){
      p.pb(i);
    }
  }
  int ask = 0, lim;
  d = 0;
  for(lim = 0;lim<20;lim++){
    cout << p[ask] << '\n';
    fflush(stdout);
    cin >> res;
    if(res[0] == 'y'){
      d++;
      if(p[ask]<10){
	lim++;
	cout << p[ask]*p[ask] << '\n';
	fflush(stdout);
	cin >> res;
	if(res[0] == 'y') d++;
	lim ++;
      }
    }
    ask++;
  }
  if(d>1) puts("composite");
  else puts("prime");
  return 0;
}

