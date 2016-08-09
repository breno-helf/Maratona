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

int main(){
  string s1 = "I hate", s2 = " that I love", s3 = " that I hate";
  int n;
  cin >> n;
  cout << s1;
  for(int i=1;i<n;i++){
    if(i%2) cout << s2;
    else cout << s3;
  }
  cout << " it\n";
  return 0;
}




