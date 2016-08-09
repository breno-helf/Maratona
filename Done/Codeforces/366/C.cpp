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

const int MAXN=312345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, q;

queue<pii> f;

map<int,int> r;

map<int,int> d;

map<int,int> k;

int main(){
  scanf("%d%d", &n, &q);
  int u = 0, temp = 0;
  for(int i=0;i<q;i++){
    int a, b;
    scanf("%d%d", &a, &b);
    
    if(a == 1){
      u++;
      r[b]++;
      f.push(mp(++temp, b));
      d[b] = temp;
    }

    if(a == 2){
      u -= r[b];
      r[b] = 0;
      k[b] = d[b];
    }

    if(a == 3){
      while(!f.empty()){
	int vi = (f.front()).first, id = (f.front()).second;

	if(vi > b) break;

	f.pop();

	if(vi > k[id]){
	  u--;
	  r[id]--;
	}
      }
    }
    printf("%d\n", u);
  }
  return 0;
}
	
