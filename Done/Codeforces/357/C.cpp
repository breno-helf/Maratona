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

int n, op[MAXN];
char s[MAXN][15], re[MAXN][15], ins[7] = {'i','n','s','e','r','t'}, rem[10] = {'r','e','m','o','v','e','M','i','n'}, mn[7] = {'g','e','t','M','i','n'};
int m, ho[MAXN], tre;

int main(){
  scanf("%d", &n);
  priority_queue<int> q;
  //memet(ho,INF,ho);
  tre = 0;
  for(int i=0;i<n;i++){
    scanf("%s", s[i]);
    if(s[i][0] == 'i'){
      scanf("%d", &op[i]);
      op[i]*=-1;
      q.push(op[i]);
      strcpy(re[tre], ins);
      ho[tre++] = op[i];
    }
    else if(s[i][0] == 'r'){
      if(q.empty()){
	strcpy(re[tre], ins);
	ho[tre++] = -1000000000;
	q.push(-1000000000);
      }
      q.pop();
      strcpy(re[tre++], rem);
    }
    else if(s[i][0] == 'g'){
      scanf("%d", &op[i]);
      op[i] *= -1;
      if( !(q.empty()) ){
	if((op[i] == q.top())){
	  strcpy(re[tre],mn);
	  ho[tre++] = op[i];
	}
	else{
	  int e = 1;
	  while( !(q.empty()) && e == 1 ){
	    if((q.top() > op[i])){
	      strcpy(re[tre++], rem);
	      e = 1;
	      q.pop();
	    }
	    else e = 0;
	  }
	  if( !(q.empty()) ){
	    if( q.top() == op[i]){
	      strcpy(re[tre], mn);
	      ho[tre++] = op[i];
	    }
	    else{
	      strcpy(re[tre],ins);
	      ho[tre++] = op[i];
	      q.push(op[i]);
	      strcpy(re[tre],mn);
	      ho[tre++] = op[i];
	    }
	  }
	  else{
	    strcpy(re[tre],ins);
	    ho[tre++] = op[i];
	    q.push(op[i]);
	    strcpy(re[tre],mn);
	    ho[tre++] = op[i];
	  }
	}
      }
      else{
	strcpy(re[tre],ins);
	ho[tre++] = op[i];
	q.push(op[i]);
	strcpy(re[tre],mn);
	ho[tre++] = op[i];
      }
    }
  }
  printf("%d\n", tre);
  for(int i=0;i<tre;i++){
    printf("%s", re[i]);
    if(re[i][0] == 'i' || re[i][0] == 'g'){
      printf(" %d", -ho[i]);
    }
    printf("\n");
  }
  return 0;
}
