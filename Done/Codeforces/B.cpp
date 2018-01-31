#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int cur = 0;

  vector<ll> perfect;
  int sum = 10;
  perfect.push_back(0);

  for (ll num = 19; cur < 10000;) {    
    if (sum == 10) {
      perfect.push_back(num);
      //printf("%lld\n", num);
      cur++;
    }
    num++;
    int qtd = 0, a = num;
    while (a % 10 == 0) {
      a /= 10;
      qtd++;
    }
    sum = sum - qtd * 9 + 1;
  }

  int k;
  scanf("%d", &k);
  printf("%lld\n", perfect[k]);
}
