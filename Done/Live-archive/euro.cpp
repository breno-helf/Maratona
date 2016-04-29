#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const int cnst=200;



int num[MAXN],m[6],mx,t,fila[100*MAXN],ini,fim;
double media;

int main(){
	scanf("%d", &t);
	for(int tt=0;tt<t;tt++){
		memset(num,-1,sizeof(num));
		num[0+cnst]=0;
		memset(fila,0,sizeof(fila));
		for(int i=0;i<6;i++)	scanf("%d", &m[i]);
		ini=0;
		fim=0;
		mx=0;
		media=0;
		fila[fim++]=0;
		while(ini!=fim){
			int atual=fila[ini];
			if(atual<-100 || atual>200){
				ini++;
				continue;
			}
			for(int i=0;i<6;i++){
				if(num[atual+cnst-m[i]]==-1){
					num[atual+cnst-m[i]]=num[atual+cnst]+1;
					fila[fim++]=atual-m[i];
				}
				if(num[atual+cnst+m[i]]==-1){
					num[atual+cnst+m[i]]=num[atual+cnst]+1;
					fila[fim++]=atual+m[i];
				}
			}
			ini++;
		}
		for(int i=1;i<=100;i++){
			mx=max(mx,num[i+cnst]);
			media+=num[i+cnst];
		}
		media/=100;
		printf("%.2lf %d\n", media, mx);
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
			
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		


