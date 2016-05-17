//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=5123;
const int INF=0x3f3f3f3f;

int n, resp[MAXN];
int mx ,num[MAXN], c, t[MAXN];

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++) scanf("%d", &t[i]);
  for(int i=1;i<=n;i++){
    mx = -1;
    memset(num,0,sizeof(num));
    for(int k=i;k<=n;k++){
      if((++num[t[k]])>=mx){
	(num[t[k]]==mx) ? c = min(c,t[k]) : c = t[k], resp[c]++, mx=num[c];
	//debug("[-->] %d %d %d %d\n", t[k], num[t[k]], c, resp[c]);
      }
      else resp[c]++;
      //debug("[-->] %d %d\n", c, resp[c]);
    }
  }
  for(int i=1;i<n;i++) printf("%d ", resp[i]);
  printf("%d\n", resp[n]);
  return 0;
}

