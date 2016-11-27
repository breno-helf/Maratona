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

const int MAXN=121;
const int INF=0x3f3f3f3f;

ll n;


struct matrix{
  ll a[2][2];
  matrix() {
    a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
  }

  matrix operator+(matrix q) {
    matrix ret;
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	ret.a[i][j] = (a[i][j] + q.a[i][j]);

    return ret;
  }

  matrix operator*(matrix q) {
    matrix ret;
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++)
          ret.a[i][j] += (a[i][k]*(q.a[k][j]));

       
      }
    } 
    return ret;
  }

  bool operator==(matrix q) {
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	if(a[i][j] != q.a[i][j]) return 0;
    return 1;
  }
};

matrix fib, id;


matrix fexp(matrix a, int e) {
  matrix ret;
  ret = id;
  matrix pow = a;
  for(int i = 0; i < 32; i++) {
    if(e&(1<<i)) ret = ret*pow;
    pow = pow*pow;
  }
  return ret;
}



int main() {
	cin >> n;
	fib.a[0][1] = fib.a[1][0] = fib.a[1][1] = 1;
	id.a[0][0] = id.a[1][1] = 1;
	int ini = 3, fim = 89;
		
	while(ini < fim) {
		int meio = (ini + fim + 1)/2;
		matrix r = fexp(fib, meio);
		ll val = r.a[1][0];
		//cout << val << endl;
		if(val <= n)
			ini = meio;
		else if(val > n)
			fim = meio - 1;
	}
	cout << ini - 2 << '\n';

}
