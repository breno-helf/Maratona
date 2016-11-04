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

const int MAXN=1123456;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int n, a[MAXN];

int main() {
  int i;
  scanf("%d", &n);
  int k = 1;
  for(i = 0; k <= n; i++, k += 2)
    a[i] = k;
  if(k >= n) k -= 2;
  if(k == n) k -= 2;
  debug("=> %d\n", k);
  for(i = i; k > 0; i++, k -= 2)
    a[i] = k;
  k = 2;

  for(i = i; k <= n; i++, k += 2)
    a[i] = k;
  if(k >= n) k -= 2;
  if(k == n) k -= 2;
  for(i = i; k > 0; i++, k -= 2)
    a[i] = k;
  a[i] = n;
  for(i = 0; i < 2*n; i++)
    printf("%d ", a[i]);
  putchar('\n');
  
}

