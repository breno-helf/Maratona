//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

char s[MAXN];

int alf[30];

int n;

int main(){
  int resp=0;
  scanf("%d", &n);
  scanf("%s", s);
  if(n>26) printf("-1\n");
  else{
    for(int i=0;i<n;i++){
      alf[s[i]-'a'] = 2;
    }
    for(int i=0;i<n;i++){
      if(alf[s[i]-'a']==0 || alf[s[i]-'a']==2){
	alf[s[i]-'a']=1;
      }
      else{
	for(int k=0;k<26;k++){
	  if(alf[k]==0){
	    s[i] = 'a' + k;
	    alf[k]=1;
	    debug("Troquei pos %d pra %c\n", i+1, k+'a');
	    resp++;
	    break;
	  }
	}
      }
    }
    printf("%d\n", resp);
  }
  return 0;
}


