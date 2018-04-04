//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 21;
const int INF = 0x3f3f3f3f;
const ll  MOD = 1000000007;

struct matrix {
  ll a[MAX][MAX];
  int n;
    
  matrix(int N = MAX) {
    n = N;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	a[i][j] = 0;
  }
  
  matrix operator+(matrix q) {
    matrix ret = matrix(n);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	ret.a[i][j] = (a[i][j] + q.a[i][j])%MOD;

    return ret;
  }

  matrix operator*(matrix q) {
    matrix ret = matrix(n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
	for(int k = 0; k < n; k++)
	  ret.a[i][j] += (a[i][k]*(q.a[k][j]))%MOD;

	ret.a[i][j] %= MOD;
      }
    } 
    return ret;
  }

  bool operator==(matrix q) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	if(a[i][j] != q.a[i][j]) return 0;
    return 1;
  }
};

void print_matrix(matrix M, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%lld ", M.a[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

ll s[MAX], c[MAX], g[MAX];

matrix fexp(matrix a, matrix id, ll e) {
  matrix ret = matrix(a.n);
  ret = id;
  matrix pow = a;
  for(int i = 0; i < 60; i++) {
    if(e & (1LL<<i)) {
      ret = ret * pow;
      // printf("<<<<<<<<<<<<<<<<<<<<\n");
      // print_matrix(ret, ret.n);
      // printf("\n");
      // print_matrix(pow, pow.n);
      // printf(">>>>>>>>>>>>>>>>>>>>\n\n");
    }
    pow = pow * pow;
  }
  return ret;
}

ll calculate(int r, int x) {
  ll ret = 0;
  for (int i = 0; i < r; i++) {
    ret += s[x - i - 1] * c[i];
    ret %= MOD;
  }
  return ret;
}

int main() {
  ll n;
  int r, k;
  int T;
  scanf("%d", &T);
  
  while (T--) {
    scanf("%lld%d%d", &n, &r, &k);

    for (int i = 0; i < r; i++) {
      scanf("%lld", s + i);
    }

    for (int i = 0; i < r; i++) {
      scanf("%lld", c + i);
    }

    for (int i = r; i < r + k; i++) {
      s[i] = calculate(r, i);
    }
    
    matrix result = matrix(r + k);
    matrix M = matrix(r + k);
    matrix V = matrix(r + k);
    matrix id = matrix(r + k);

    // a1 a2 ... aR 0 0 ... 0
    // 1 0 .... 0 0 0 0 ... 0
    // 0 1 0 .... 0 0 0 ... 0
    // .
    // .
    // 0 0 0 ... 1 0 0  ... 1
    // 0  0  ... 0  1 0 ... 0
    // 0  0  ... 0  0 1 ... 0
    // .
    // .
    // 0  0  ... 0  0 ... 1 0

    
    for (int i = 0; i < r; i++) {
      M.a[0][i] = c[i];
    }

    M.a[r][r - 1] = M.a[r][r + k - 1] = 1;
    
    for (int i = 1; i < r; i++) {
      M.a[i][i - 1] = 1;
    }

    for (int i = 1; i < k; i++) {
      M.a[r + i][r + i - 1] = 1;
    }
    
    for (int i = 0; i < r; i++) {
      V.a[i][0] = s[r + k - 2 - i];
    }

    for (int i = 0; i < r + k; i++) {
      id.a[i][i] = 1;
    }
    
    M = fexp(M, id, (ll)(n * k - (k - 1)));
    result = M * V;
    // printf("%lld %d %d\n", n, r, k);
    // print_matrix(result, r + k);
    // printf("-----------\n\n");

    printf("%lld\n", result.a[r][0]);
  }
  
  
  return 0;
}
