#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

int fac[MAXN][2],dist,num,crivo[MAXN],a,b,t;

vector<int> p;

int main(){
	for(int i=0;i<=1000000;i++) crivo[i]=1;
	for(int i=2;i*i<=1000000;i++){
		if(crivo[i]){
		//	p.push_back(i);
			int k=i*i;
			while(k<=1000000){
				crivo[k]=0;
				k+=i;
			}
		}
	}
	for(int i=2;i<=1000000;i++) if(crivo[i]==1)	p.push_back(i); 
	t=0;
	while(1){
		t++;
		memset(fac,0,sizeof(fac));
		num=0;
		dist=0;
		scanf("%d%d", &a, &b);	
		if(a==0 && b==0) break;
		int tam=p.size();
	//	debug("tam eh %d\n", tam);
		for(int i=0;a>1;i++){
			if(i==tam) break;
			while(a%p[i]==0 && a>1){
					//if(fac[p[i]][0]==0) num[0]++;
				fac[p[i]][0]++;
				a/=p[i]; // 24=2^3*3 -- 32=2^5
			}
		}
		for(int i=0;b>1;i++){
		//	if(i==tam) break;
			while(b%p[i]==0 && b>1){
					//if(fac[p[i]][1]==0) num[1]++;
				fac[p[i]][1]++;
				b/=p[i];
			}
		}
		for(int i=2;i<=1000000;i++){
			if(fac[i][0]!=fac[i][1]) dist+=abs(fac[i][0]-fac[i][1]);
			if(fac[i][0] || fac[i][1]) num++;
		}
		printf("%d. %d:%d\n",t, num,dist);
	}
	return 0;
}
