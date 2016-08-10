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

const int MAXN=12314;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int gcd(int a, int b){
  if(b==0) return a;
  else return gcd(b, a%b);
}


int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int g = gcd( abs(a - c), abs(b - d));
    printf("%d\n", g+1);
  }
}




