//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

char resp[3];

int t, n, p[MAXN];
pii m[MAXN];

int main(){
  scanf("%d", &t);
  for(int tt=1;tt<=t;tt++){
    scanf("%d", &n);
    int total=0;
    int top=0;
    memset(m,0,sizeof(m));
    memset(p,0,sizeof(p));
    for(int i=0;i<n;i++){
      scanf("%d", &p[i]);
      m[i].first=p[i];
      m[i].second=i;
      total+=p[i];
    }
    printf("Case #%d:", tt);
    sort(&m[0], &m[n]);
    while(m[n-1].first != m[n-2].first){
      printf(" %c", m[n-1].second + 'A');
      m[n-1].first--;
    }
    while(top <n-2){
      if(m[top].first >= 2){
	printf(" %c%c", m[top].second + 'A', m[top].second + 'A');
	m[top].first -= 2;
      }
      else{
	printf(" %c",  m[top].second + 'A');
	m[top].first--;
      }
      if(m[top].first==0) top++;
    }
    while(m[n-1].first>0 && m[n-2].first>0){
      printf(" %c%c",  m[n-1].second + 'A', m[n-2].second + 'A');
      m[n-1].first--;
      m[n-2].first--;
    }
    printf("\n");
  }
  return 0;
}
      
    

