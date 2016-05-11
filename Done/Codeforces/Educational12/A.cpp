#include<bits/stdc++.h>
using namespace std;

#define debug(args...)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

char s[10];
int a,ta,b,tb;
int sth,stm,temp;
int resp,go;

int main(){
  scanf("%d%d", &a, &ta);
  scanf("%d%d", &b, &tb);
  scanf("%s", s);
  sth=10*(s[0]-'0') + s[1]-'0';
  stm=10*(s[3]-'0') + s[4]-'0';
  temp=60*sth+stm;
  go=300;
  resp=0;
  int last=24*60;
  for(int i=300;i<last;i+=b)  if(i+tb>temp && i<temp+ta) resp++;
  printf("%d\n", resp);
  return 0;
}
    




