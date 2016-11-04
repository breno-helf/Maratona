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

const int MAXN=1212;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;


int main(){
  int h, m;
  scanf("%d:%d",&h,&m);
  int mr;
  scanf("%d",&mr);
  int sh=(m+mr)/60;
  m=(m+mr)%60;
  h=(h+sh)%24;
  printf("%02d:%02d\n",h,m);			  
}
