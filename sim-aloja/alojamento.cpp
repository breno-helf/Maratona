#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n,m,resp,atual;

char g[MAXN][MAXN];

int main(){
  scanf("%d%d", &n, &m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf(" %c", &g[i][j]);
  resp=0;
  atual=0;
  for(int i=0;i<n;i++){
    if(!(i%2)){
      for(int j=0;j<m;j++){
	if(g[i][j]=='.') atual++;
	else if(g[i][j]=='L') atual=0;
	if(atual>resp) resp=atual;
      }
    }
    else{
      for(int j=m-1;j>=0;j--){
	if(g[i][j]=='.') atual++;
	else if(g[i][j]=='L') atual=0;
	if(atual>resp) resp=atual;
      }
    }
  }
  printf("%d\n", resp);
}
  


