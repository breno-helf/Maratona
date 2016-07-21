//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

int m[MAXN][MAXN];

char num[MAXN];

int n, resp, dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

map<char,pii> pos;

bool check(int x, int y){
  if(x<0 || y<0) return 0;
  else return 1;
}



int main(){
  resp = 0;
  scanf("%d", &n);
  scanf("%s", num);
  m[0][0] = m[0][1] = m[0][2] = m[1][0] = m[1][1] = m[1][2] = m[2][0] = m[2][1] = m[2][2] = m[3][1] = 1;
  pos['0'] = mp(3,1);
  pos['1'] = mp(0,0);
  pos['2'] = mp(0,1);
  pos['3'] = mp(0,2);
  pos['4'] = mp(1,0);
  pos['5'] = mp(1,1);
  pos['6'] = mp(1,2);
  pos['7'] = mp(2,0);
  pos['8'] = mp(2,1);
  pos['9'] = mp(2,2);
  for(int k=0;k<4;k++){
    int e = 0;      
    for(int i=0;i<n;i++){
      if(check(pos[num[i]].first + dx[k], pos[num[i]].second + dy[k])){
	if(!m[pos[num[i]].first + dx[k]][pos[num[i]].second + dy[k]]){
	  e = 1;
	  debug("Pisei fora em %d %d\n", pos[num[i]].first + dx[k], pos[num[i]].second + dy[k]);
	}
      }
      else e = 1;
    }
    if(!e){
      debug("Entrou em %d %d\n", dx[k], dy[k]);
      resp = 1;
    }
  }
  if(resp) puts("NO");
  else puts("YES");
  return 0;
}


