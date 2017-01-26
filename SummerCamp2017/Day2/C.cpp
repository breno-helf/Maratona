#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 1123;

long long ar[MAXN], at[MAXN];

map<int,int> a, b;

int main() {
  long long d, r, t;
  cin >> d >> r >> t;

  for(int i = 4; i <= 100; i++) {
    ar[i] = ar[i-1] + i;
    a[ar[i]] = i;
  }

  for(int i = 3; i <= 100; i++) {
    at[i] = at[i-1] + i;
    b[at[i]] = i;
  }

  auto _ita = a.find(r);
  auto _itb = b.find(t);
  if (_ita != a.end() && _itb != b.end() && _itb->second - _ita->second == d) {
      printf("0\n");
      return 0;
  }

  for (int i = 3+d; i <= 100; i++) {
      int left = r - ar[i];
      // left should be > 0
      auto _itb = b.find(t + left);
      if (_itb != b.end() &&  i - _itb->second == d) {
          printf("%d\n", left);
          return 0;
      }
  }
}
