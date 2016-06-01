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


int a[MAXN], n, h;

int main(){
  int resp=0;
  scanf("%d%d", &n, &h);
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    if(a[i]>h) resp++;
    resp++;
  }
  printf("%d\n", resp);
  return 0;
}








