#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=15;
const int INF=0x3f3f3f3f;

char a[MAXN],b[MAXN];
char resp[MAXN];
int tama,tamb,tamr;


int main(){
  while(1){
    memset(resp,0,sizeof(resp));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s %s", a, b);
    if(strlen(a)==1 && strlen(b)==1) if(a[0]=='0' && b[0]=='0') break;
    tama=strlen(a);
    tamb=strlen(b);
    tamr=13;
    int cin=0,cout=0;
    for(int i=tama-1, j=tamb-1; (j>=0 || i>=0) || cout!=0; i--, j--){
      int vala=0,valb=0,valr;
      cin=cout;
      cout=0;
      if(i>=0) (a[i]>='0' && a[i]<='9') ? vala = a[i]-'0' : vala = a[i]-'A'+10;
      if(j>=0) (b[j]>='0' && b[j]<='9') ? valb = b[j]-'0' : valb = b[j]-'A'+10;
      valr = vala + valb + cin;
      if(valr>=36){
	cout=1;
	valr-=36;
      }	
      (valr<10) ? resp[tamr] = valr + '0' : resp[tamr] = valr+'A'-10;
      tamr--;
    }
    int c=1;
    for(int i=0;i<14;i++){
      if(resp[i]==0 && c) continue;
      else{
	c=0;
	printf("%c", resp[i]);
      }
    }
    printf("\n");
  }
  return 0;
}

