//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const double eps = 0.0000000001;

int n, resp, t;
double c[MAXN], nx[MAXN];

int main(){
  scanf("%d%d", &n, &t);
  resp=0;
  for(int i=1;i<=n;i++){
    for(int k=1;k<=n;k++) c[k] = nx[k], nx[k] = 0;
    if(i==1) c[i] = t;
    //for(int k=1;k<=n;k++) debug("%.5lf ", c[k]);
    //debug("\n");
    for(int k=1;k<=i;k++){
      if(c[k]>1-eps){
	nx[k] += (c[k]-1)/2;
	nx[k+1] += (c[k]-1)/2;
	c[k] = 1;
	resp++;
      }
    } 
  }
  printf("%d\n", resp);
  return 0;
}




