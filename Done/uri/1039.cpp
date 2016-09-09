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

const int MAXN=12321;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

long double r[3], x[3], y[3], dist;

int main() {
  while(cin >> r[1] >> x[1] >> y[1] >> r[2] >> x[2] >> y[2]) {
    dist = sqrt((x[1] - x[2])*(x[1] - x[2]) + (y[1] - y[2])*(y[1] - y[2]));
    if(dist + r[2] <= r[1]) puts("RICO");
    else puts("MORTO");
  }
}
