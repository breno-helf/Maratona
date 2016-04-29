#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const double pi=3.141592;
const double eps=0.00001;

int v,e,d,h;
double iv;
double vol;
int main(){
  scanf("%d%d%d%d", &d, &h, &v, &e);
  iv=(d*d);
  iv*=pi/4;
  iv*=e;
  vol=h*(d*d);
  vol*=pi/4;
  if(iv>v) printf("NO\n");
  else printf("YES\n%.5lf\n", vol/(v-iv));
  return 0;
}


