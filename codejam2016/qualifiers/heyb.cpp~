#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

char s[MAXN];
int t,c[MAXN],h,m;

int main(){
	scanf("%d", &t);
	for(int tt=1;tt<=t;tt++){
		memset(s,0,sizeof(s));
		memset(c,0,sizeof(c));
		scanf("%s", s);
		h=1;
		if(s[0]=='+') m=1;
		else m=0;
		int tam=strlen(s);
		for(int i=0;i<tam;i++){
			if(s[i]=='+'){
				if(m==0){
					m=1;
					h++;
				}
			//	v[i+1]=1;
				c[i+1]=h;
				debug("%d ", h);
			}
			else{
				if(m==1){
					m=0;
					h++;
				}
				c[i+1]=h;
				debug("%d ", h);
			}
		}
		debug("\n");
		printf("Case #%d: %d\n", tt, c[tam]-m);
	}
	return 0;
}		
		
		
		
		
		
		
		
		
		
