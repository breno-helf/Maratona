//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

ll a[MAXN], n, d[MAXN];
ll acc[MAXN];
ll neg[MAXN];
ll mp=0,mn=0;

int main(){
  scanf("%lld", &n);
  for(int i=0;i<n;i++){
    scanf("%lld", &a[i]);
    if(i>0) d[i] = a[i] - a[i-1];
  }
  for(int i=1;i<n;i++){
    acc[i] = acc[i-1] + d[i];
    if(acc[i]<0) acc[i]=0;
    mp = max(mp,acc[i]);
  }
  for(int i=1;i<n;i++){
    neg[i] = neg[i-1] + d[i];
    if(neg[i]>0) neg[i]=0;
    mn = min(mn, neg[i]);
  }
  printf("%lld\n", max(mp,abs(mn)));
  return 0;
}

