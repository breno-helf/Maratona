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

const int MAXN=1231;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

long double r[2], x[2], y[2];

long double dist;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &r[0], &x[0], &y[0], &r[1], &x[1], &y[1]);
    dist = sqrt( (x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]) );
    if(r[1] + dist <= r[0]) puts("Rich");
    else puts("Dead");
  }
}




