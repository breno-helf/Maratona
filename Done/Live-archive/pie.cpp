#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const double eps=0.00001;
const double pi=3.14159265359;

double resp,ini,fim,meio;

int t,r[MAXN],n,f,c;

void bb(){
  ini=0.0;
  fim=pi*100000000.0;
  while(ini+eps<=fim){
    meio=(ini+fim)/2;
    c=0;
    for(int i=0;i<n;i++){
      c+=(int)((pi*(double)r[i]*(double)r[i])/meio);
    }
    if(c>f){
      ini=meio;
      resp=meio;
    }
    else fim=meio;
  }
  // debug("ini eh %.2lf\n\n", ini);
}

int main(){
  scanf("%d", &t);
  for(int tt=0;tt<t;tt++){
    scanf("%d%d", &n, &f);
    memset(r,0,sizeof(r));
    for(int i=0;i<n;i++) scanf("%d", &r[i]);
    bb();
    printf("%.4lf\n", resp);
  }
  return 0;
}
