//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=100;
const int INF=0x3f3f3f3f;

int n, t[MAXN];

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    int a;
    scanf("%d", &a);
    t[a]=1;
  }
  int br=0;
  int resp=0;
  for(int i=1;i<=90;i++){
    resp++;
    if(t[i]==1) br=0;
    else br++;
    if(br==15) break;
  }
  printf("%d\n", resp);
  return 0;
}


