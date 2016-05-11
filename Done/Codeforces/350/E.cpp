//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define deb(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=512345;
const int INF=0x3f3f3f3f;

int n, m, p;

stack<int> s;

char br[MAXN], op[MAXN];

int pa[MAXN];
int marc[MAXN];

int arruma(int x){
  if(marc[x]!=0){
    if(marc[x]>0){
      if(pa[x]+1<n) return (pa[x]=arruma(pa[x]+1)-1) +1;
      else return arruma(x-1);
    }
    else{
      if(pa[x]-1>=0) return (pa[x]=arruma(pa[x]-1)+1) -1;
      else return arruma(x+1);
      }
  }
  else return x;
}

int main(){
  scanf("%d%d%d", &n, &m, &p);
  scanf("%s", br);
  scanf("%s", op);
  s.push(0);
  for(int i=1;i<n;i++){
    if(br[i]=='(') s.push(i);
    else{
      pa[s.top()] = i;
      pa[i] = s.top();
      s.pop();
    }
  }
  p--;
  for(int i=0;i<m;i++){
    deb("%d ", i);
    p = arruma(p);
    // while(marc[p]!=0){
    //   if(marc[p]>0){
    // 	if(pa[p]+1<n){
    // 	  p = pa[p]+1;
    // 	}
    // 	else p--;
    //   }
    //   else{
    // 	if(pa[p]-1>=0) p = pa[p]-1;
    // 	else p++;
    //   }
    // }
    deb("[%d] --> %d\n", i, p);
    if(op[i]=='L'){
      p--;
      deb("Andei pra esquerda\n");
    }
    else if(op[i]=='R'){
      p++;
      deb("Andei pra direita\n");
    }
    else{
      if(pa[p]>p){
	marc[p] = 1;
	marc[pa[p]] = -1;
	deb("Deletei de %d ateh %d\n", p, pa[p]);
	if(pa[p]+1<n) p = pa[p]+1;
	else p--;
      }
      else{
	marc[pa[p]] = 1;
	marc[p] = -1;
	deb("Deletei de %d ateh %d\n", pa[p], p);
	if(p+1<n) p++;
	else p = pa[p]-1;
      }
    }
  }
  int c=0;
  for(int i=0;i<n;i++){
    c += marc[i];
    if(marc[i]==-1) continue;
    if(c==0) printf("%c", br[i]);
  }
  printf("\n");
  return 0;
}
  


