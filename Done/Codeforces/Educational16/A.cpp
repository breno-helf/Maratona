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

char g[5];

int resp;


int main() {
  scanf(" %s", g);
  resp = 8;
  if(g[0] == 'a' || g[0] == 'h') resp -= 3;

  if(g[1] == '8' || g[1] == '1') {
    if(resp == 5) resp -= 2;
    else resp -= 3;
  }

  printf("%d\n", resp);
}


