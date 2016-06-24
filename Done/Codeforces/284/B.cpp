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

const int MAXN=3123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, m;

map<string, string> change;

vector<string> lec;

int main(){
  cin >> n >> m;
  for(int i=0;i<m;i++){
    string a, b;
    cin >> a >> b;
    if(b.size() < a.size()){
      change[a] = b;
      change[b] = b;
    }
    else{
      change[a] = a;
      change[b] = a;
    }
  }
  for(int i=1;i<=n;i++){
    string c;
    cin >> c;
    cout << change[c];
    if(i==n) cout << '\n';
    else cout << ' ';
  }
  return 0;
}
  
  




