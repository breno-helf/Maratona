//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

char s[MAXN];

int main(){
  scanf("%s", s);
  int tam = strlen(s);
  int sum = 0;
  for(int i=0;i<tam;i++) sum += s[i];
  if(!(sum%3)) printf("2\n");
  else printf("1\n%d\n", sum%3);
  return 0;
}
