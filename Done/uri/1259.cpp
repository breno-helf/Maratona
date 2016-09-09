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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, v[MAXN];

bool cmp(int a, int b) {
  if(a%2 && !(b%2)) return 0;
  else if(!(a%2) && b%2) return 1;
  else if(a%2) return (a > b);
  else return (b > a);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(v, v + n, cmp);
  for(int i = 0; i < n; i++) cout << v[i] << '\n';
}

