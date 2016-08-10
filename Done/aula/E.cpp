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

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int crivo[MAXN], resp;

map<int,int> d;

int main () {
  for (int i = 2; i*i <= 10000; i++) if (crivo[i] == 0) for (int j = i*i; j <= 10000; j += i) crivo[j] = i;
  for (int i = 0; i < 10; i++) {
    int a;
    scanf("%d", &a);
    if (a == 1) continue;
    while (crivo[a] != 0) {
      //      debug("Travei? %d\n", a);
      d[crivo[a]]++;
      a /= crivo[a];
    }
    d[a]++;
  }
  resp = 1;
  for (auto p : d){
    resp *= (p.second + 1);
    //    resp %= 1000000;
  }
  resp %= 10;
  printf("%d\n", resp);
  return 0;
}





