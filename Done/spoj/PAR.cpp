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

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a, b;

string p1, p2;


int main(){
  int t = 1;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    cin >> p1 >> p2;
    cout << "Teste "<< t++ << endl;
    for(int i=0;i<n;i++){
      cin >> a >> b;
      if((a+b)%2) cout << p2 << endl;
      else cout << p1 << endl;
    }
    cout << endl;
  }
  return 0;
}
