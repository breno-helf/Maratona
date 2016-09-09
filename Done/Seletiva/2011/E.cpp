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

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

struct ponto {
  double x, y;
  ponto(double x = 0, double y = 0): x(x), y(y) {}
  ponto operator +(ponto q) { return ponto(x + q.x, y + q.y); }
  ponto operator -(ponto q) { return ponto(x - q.x, y - q.y); }
  double operator *(ponto q) { return (x*q.x + y*q.y); }
  double operator ^(ponto q) { return (x*q.y - y*q.x); }
  double mod() { return sqrt(x*x + y*y); }
};

int n;
ponto p[MAXN];
double co[MAXN], si[MAXN];

int main() {
  int resp = 0;
  int c = 0, aux = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  for(int i = 1; i < n; i++) {
    aux += p[i].x*p[i+1].y - p[i].y*p[i+1].x;
  }
  aux += p[n].x*p[1].y - p[n].y*p[1].x;
  
  if(aux > 0) c = 1;
  if(c == 1) {
    for(int i = 1; i <= n; i++) {
      if(i > 1 && i < n) {
	ponto a, b;
	a = p[i-1] - p[i];
	b = p[i+1] - p[i];
	si[i] = ((a^b)/(a.mod()*b.mod()));
      }
      else if(i == 1) {
	ponto a, b;
	a = p[n] - p[i];
	b = p[i+1] - p[i];
	si[i] = ((a^b)/(a.mod()*b.mod()));
      }
      else {
	ponto a, b;
	a = p[i-1] - p[i];
	b = p[1] - p[i];
      si[i] = ((a^b)/(a.mod()*b.mod()));
      }
    }
  }

  else {
    for(int i = 1; i <= n; i++) {
      if(i > 1 && i < n) {
	ponto a, b;
	b = p[i-1] - p[i];
	a = p[i+1] - p[i];
	si[i] = ((a^b)/(a.mod()*b.mod()));
      }
      else if(i == 1) {
	ponto a, b;
	b = p[n] - p[i];
	a = p[i+1] - p[i];
	si[i] = ((a^b)/(a.mod()*b.mod()));
      }
      else {
	ponto a, b;
	b = p[i-1] - p[i];
	a = p[1] - p[i];
	si[i] = ((a^b)/(a.mod()*b.mod()));
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    if(si[i] >= 0) resp++;
  }
  printf("%d\n", resp);
}

  
