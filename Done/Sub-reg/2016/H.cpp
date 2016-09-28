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

const int MAXN=52;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

string a, b, c;
int tam;
int main() {
  cin >> a;
  tam = a.size();
  b = c = "";
  for(int i = 0; i < tam; i++)
    if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') b += a[i];

  tam = b.size();
  for(int i = tam - 1; i >= 0; i--) c += b[i];

  if(b == c) puts("S");
  else puts("N");
}
