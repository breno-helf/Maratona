//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

int n, a[MAXN], resp, p[MAXN];

int pmx, pmn;

int bnmn, bnmx;

int main(){
  scanf("%d", &n);
  for(int i=1;i<=101;i++) p[i] = i;
  for(int i=1;i<=n;i++){
    scanf("%d", &a[i]);
    if(a[i]==1) pmn = i;
    if(a[i]==n) pmx = i;
  }
  if(pmn < pmx) bnmn = 1;
  else bnmn = n;

  if(pmx < pmn) bnmx = 1;
  else bnmx = n;

  printf("%d\n", ((abs(bnmn-pmx))>abs(bnmx-pmn)) ? (abs(bnmn-pmx)) : (abs(bnmx-pmn)) );
  return 0;
}
  





