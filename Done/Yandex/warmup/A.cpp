//This code was made by Breno Moura, Codeforces Handle: Brelf
//If you are trying to hack me I wish you can get it, Good Luck :D
//However if we are in the last five minutes of the contest, GO AWAY
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

char p[MAXN], v[MAXN], c[MAXN];

int main(){
  int tamv=0, tamc=0;
  scanf("%s", p);
  int tam = strlen(p);
  for(int i=0;i<tam;i++){
    if((p[i]=='a' || p[i]=='e' || p[i]=='i' || p[i]=='u' || p[i]=='o' || p[i]=='y')){
      v[tamv]=p[i];
      tamv++;
    }
    else{
      c[tamc]=p[i];
      tamc++;
    }
  }
  if(strcmp(v,c)>0) printf("Vowel\n");
  else printf("Consonant\n");
  return 0;
}






