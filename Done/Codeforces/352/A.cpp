//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

int n;
int aux;
int resp;

char s[MAXN];


int main(){
  scanf("%d", &n);
  int tam=1;
  for(int i=1;i<1010;i++){
    aux=i;
    if(aux/10>0){
      if(aux/100>0){
	if((aux/1000)>0){
	  s[tam++]= '0' + aux/1000;
	  aux%=1000;
	}
	s[tam++] = '0' + aux/100;
	aux%=100;
      }
      s[tam++] = '0' + aux/10;
      aux%=10;
    }
    s[tam++] = '0' + i%10;
  }
  //debug("%d \n\n", tam);
  //for(int i=1;i<=200;i++) debug("%c", s[i]);
  //debug("\n");
  printf("%c\n", s[n]);
  return 0;
}




