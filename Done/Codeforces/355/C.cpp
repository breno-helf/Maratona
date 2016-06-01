//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345;
const int INF=0x3f3f3f3f;
const int mod = (int)1000000007;

char s[MAXN];
ll freq[MAXN];
ll resp=1;

int tr(char c){
  int ret;
  if(c>='0' && c<='9') ret = c - '0';
  else if(c>='A' && c<='Z') ret = c - 'A' + 10;
  else if(c>='a' && c<='z') ret = c - 'a' + 36;
  else if(c=='-') ret = 62;
  else ret = 63;	       
  return ret;
}  

int main(){
  scanf("%s", s);
  int tam = strlen (s);
  for(int i=0;i<64;i++){
    for(int j=0;j<64;j++){
      freq[(i&j)]++;
      //for(int k=0;k<6;k++) if(!((1<<k)&i)) freq[i]*=3;
    }
  }
  for(int i=0;i<tam;i++){
    int at = tr(s[i]);
    resp *= freq[(int)at];
    resp %= mod;
  }
  printf("%I64d\n", resp);
  return 0;
}




