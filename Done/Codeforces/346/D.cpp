#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n;

int coord[MAXN][2],val[MAXN][2],resp,inix,iniy,cg;


int main(){
	resp=0;
	scanf("%d", &n);
	for(int i=0;i<=n;i++){
		scanf("%d%d", &coord[i][0], &coord[i][1]);
		if(i>0){
			val[i][0]=coord[i][0]-coord[i-1][0]+coord[i][1]-coord[i-1][1];
			if(coord[i][1]!=coord[i-1][1]) val[i][1]=1;
			else val[i][1]=0;
		}
	}
	int o=1;	
	inix=coord[0][0];
	iniy=coord[0][1];
	for(int i=1;i<n;i++){
		int prox=val[i+1][0];
		int atual=val[i][0];
		int pup=val[i+1][1];
		int a=coord[i][0],b=coord[i][1];
	//	debug("Avaliando coordenadas %d %d\n--\n", a, b);
		cg=0;
		for(int k=1;k<=n;k++){
			int x=coord[k][0],y=coord[k][1],eval=val[k][0],eup;
	//		debug("vetor %d, com ini nas coord %d %d\n", eval, x, y);
			if(pup==1 && prox>0){
				if(eval<0 && eup==1){
					if(x>a && atual<0){
						if(b>iniy && y>b) resp++,cg++;
						else if(b<iniy && y<b) resp++,cg++;
					}
					if(x<a && atual>0){
						if(b>iniy && y>b) resp++,cg++;
						else if(b<iniy && y<b) resp++,cg++;
					}
				}
			}
			if(pup==1 && prox<0){
				if(eval>0 && eup==1){
					if(x>a && atual<0){
						if(b>iniy && y>b) resp++,cg++;
						else if(b<iniy && y<b) resp++,cg++;
					}
					if(x<a && atual >0){
						if(b>iniy && y>b) resp++,cg++;
						else if(b<iniy && y<b) resp++,cg++;
					}
				}
			}	
			if(pup==0 && prox>0){
				if(eval<0 && eup==0){
					if(y>b && atual<0){
						if(a>inix && x>a) resp++,cg++;
						else if(a<inix && x<a) resp++,cg++;
					}
					if(y<b && atual>0){
						if(a>inix && x>a) resp++,cg++;
						else if(a<inix && x<a) resp++,cg++;
					}
				}
			}
			if(pup==0 && prox<0){
				if(eval<0 && eup==0){
					if(y>b && atual<0){
						if(a>inix && x>a) resp++,cg++;
						else if(a<inix && x<a) resp++,cg++;
					}
					if(y<b && atual>0){
						if(a>inix && x>a) resp++,cg++;
						else if(a<inix && x<a) resp++,cg++;
					}
				}
			}
			if(cg) continue;
		}
	}
	printf("%d\n", resp);
	return 0;
}	
