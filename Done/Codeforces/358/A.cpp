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

const int MAXN=112344;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

ll n, m, resp;

int main(){
  cin >> n >> m;
  resp = 0;
  for(int i=1;i<=m;i++){
    if(n%5 == 0) resp += n/5;
    else{
      if(n%5 == 1){
	resp += n/5;
	if(i%5 == 4) resp++;
      }
      if(n%5 == 2){
	resp += n/5;
	if(i%5 == 4 || i%5 == 3) resp++;
      }
      if(n%5 == 3){
	resp += n/5;
	if(i%5 == 2 || i%5 == 3 || i%5 == 4) resp++;
      }
      if(n%5  == 4){
	resp += n/5;
	if(i%5 == 1|| i%5 == 2 || i%5 == 3 || i%5 == 4) resp++;
      }
    }
  }
  cout << resp << '\n';
  return 0;
}







