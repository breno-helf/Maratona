#include<bits/stdc++.h>
using namespace std;

const int MAXN = 212345;
const int INF = 0x3f3f3f3f;


int a, b;

int main() {
  while(scanf("%d%d", &a, &b) != EOF) {
    int resp = max(a,b);
    printf("%d\n", resp);
  }
  return 0;
}
