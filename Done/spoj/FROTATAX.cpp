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

const int MAXN=123431;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
const double eps=1e-4;

double A, G, Ra, Rg;

double Pa, Pg;

int main(){
  scanf("%lf%lf%lf%lf", &A, &G, &Ra, &Rg);
  Pa = A*Rg;
  Pg = G*Ra;
  if(Pg <= Pa) printf("G\n");
  else printf("A\n");
  return 0;
}

