//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=11234;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;
const double pi=acos(-1.0);

inline double quad(double x) {
  return x*x;
}

struct ponto {
  double x;
  double y;
  ponto(double xx = 0, double yy = 0) {
    x = xx;
    y = yy;
  }

  ponto operator +(ponto q) {
    return ponto(x + q.x, y + q.y);
  }
  ponto operator -(ponto q) {
    return ponto(x - q.x, y - q.y);
  }
  ponto operator *(double k) {
    return ponto(k*x, k*y);
  }
  double mod() {
    return sqrt(quad(x) + quad(y));
  }  
  ponto gira(double t) {
    return ponto(x*cos(t) - y*sin(t), x*sin(t) + y*cos(t));
  }
  ponto girah(double t) {
    return ponto(x*cos(t) + y*sin(t), - x*sin(t) + y*cos(t));
  }
    
};

inline double dist(ponto a, ponto b) {
  return sqrt(quad(a.x - b.x) + quad(a.y - b.y));
}

ponto m[4];
double h, w;
double theta, alfa, args;

double ww;

int main(){  
  scanf("%lf%lf", &h, &w);

  for(int i = 0; i < 4; i++) scanf("%lf %lf", &m[i].x, &m[i].y);
 
  ponto e = m[1] - m[0];
  ponto d = m[2] - m[1];
  
  ww = dist(m[1], m[0]);
  
  theta = atan2(e.y, e.x);
  alfa = atan2(m[0].y, m[0].x);
 
  ponto sum, resp;  
  double r = ww/w;
  sum = resp = m[0];
  int g = 0;
  /*
  if(m[0].x > m[1].x) args = theta - 2*alfa, g = 1;  
  else if(m[0].y > m[3].y) args = 2*alfa - theta, g = 2;
  else args = theta;
  */
  
  if(((e.x > 0) && (d.x <=0) && (e.y >= 0) && (d.y > 0)) || ((e.x <= 0) && (d.x < 0) && (e.y > 0) && (d.y <= 0)) || ((e.x < 0) && (d.x >= 0) && (e.y <= 0) && (d.y < 0)) || ((e.x >= 0) && (d.x > 0) && (e.y < 0) && (d.y >= 0))) args = theta;
  else args = theta - 2*alfa, g = 1;
  
  
  debug("1. %lf %lf %lf\n", args, theta, alfa);
  
  for(int i = 0; i < 10000; i++) {
    sum = sum*r;
    if(g == 1) {
      if(i%2) sum = sum.girah(args);
      else sum = sum.gira(args);
    }
    if(g == 0) sum = sum.gira(args);
    if(g == 2) {
      if(!(i%2)) sum = sum.girah(args);
      else sum = sum.gira(args);
    }
		 
    resp = resp + sum; 
  }

  printf("%lf %lf\n", resp.x, resp.y);
  
  return 0;
}
