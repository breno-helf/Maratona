//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const double eps=1e-10;

struct Point{
  double x;
  double y;
};

double dist(Point q1, Point q2){
  double ret = sqrt( (q1.x-q2.x)*(q1.x-q2.x) + (q1.y-q2.y)*(q1.y-q2.y) );
  return ret;
}

Point a, b, t, g[MAXN];
int n;

double ct[MAXN], qa[MAXN], qb[MAXN];

double resp, acc;

pair<double,int> mna[MAXN], mnb[MAXN];


int main(){
  acc=0;
  resp = 1e17;
  memset(mna,INF,sizeof(mna));
  memset(mnb,INF,sizeof(mnb));
  scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &t.x, &t.y);
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%lf%lf", &g[i].x, &g[i].y); 
  for(int i=0;i<n;i++){
    ct[i] = 2*(dist(t, g[i]));
    acc += ct[i];
    qa[i] = dist(a, g[i]) + dist(g[i], t);
    qb[i] = dist(b, g[i]) + dist(g[i], t);
    mna[i] = make_pair(qa[i] - ct[i], i);
    mnb[i] = make_pair(qb[i] - ct[i], i);
  }
  sort(mna, mna+n);
  sort(mnb, mnb+n);
  for(int i=0;i<2;i++){
    for(int k=0;k<2;k++){
      if(mna[i].second!=mnb[k].second){
  	resp = min(resp, acc + mna[i].first + mnb[k].first);
      }
    }
  }
  for(int i=0;i<n;i++){
    resp = min(resp, acc - ct[i] + qa[i]);
    resp = min(resp, acc - ct[i] + qb[i]);
  }
  printf("%.14lf\n", resp);
  return 0;
}
  
