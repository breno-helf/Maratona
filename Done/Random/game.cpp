#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

char q[12][12];

int f,s,tam,b[25],r,resp;
int v[9]={-5,-4,-3,-1,0,1,3,4,5};




int main(){
	f=0;
	resp=INF;
	for(int i=0;i<4;i++){
		for(int k=0;k<4;k++){
			scanf(" %c", &q[i][k]);
			if(q[i][k]=='W') s+=(1<<(4*i+k));
		}
	}
	for(int i=0;i<3;i++){
		for(int k=0;k<3;k++){
			char a;
			scanf(" %c", &a);
			if(a=='1')	f+=(1<<(3*i+k));
		}
	}
	tam=(1<<16);		
	for(int i=0;i<tam;i++){
		r=s;		
		for(int g=0;g<16;g++){
			memset(b,0,sizeof(b));
			if((1<<g)&i){
				if(g%4==0){
					b[0]=1;
					b[3]=1;
					b[6]=1;
				}
				if(g%4==3){
					b[2]=1;
					b[5]=1;
					b[8]=1;
				}
				if(g/4==0){
					b[0]=1;
					b[1]=1;
					b[2]=1;
				}
				if(g/4==3){
					b[6]=1;
					b[7]=1;
					b[8]=1;
				}
				for(int k=0;k<9;k++){
					if(b[k]==0){
						if((1<<k)&f){
							r^=(1<<(g+v[k]));
						}
					}
				}
			}
		}
		if(r==0 || r==tam-1)	resp=min(resp,__builtin_popcount(i));
	}
	if(resp==INF) printf("Impossible\n");
	else printf("%d\n", resp);
	return 0;
}		
					
					
