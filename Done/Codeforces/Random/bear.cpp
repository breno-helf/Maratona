#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)

const int MAXN=512;
const int INF=0x3f3f3f3f;


int g[MAXN][MAXN],resp,n,m,q,ml[MAXN];


int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++){
		int atual=0;
		for(int j=1;j<=m;j++){
			scanf("%d", &g[i][j]);
			if(g[i][j]==0) atual=0;
			else atual++;
			ml[i]=max(ml[i],atual);
		}
		resp=max(resp,ml[i]);
	}
	for(int k=0;k<q;k++){
		debug("\nPasso %d\n------------------\n", k+1);
		for(int i=1;i<=n;i++) debug("O maximo da linha %d eh %d\n", i, ml[i]);
		debug("\n"); 
		int a,b;
		int calc=0;
		scanf("%d%d", &a, &b);
		if(g[a][b]){
			g[a][b]=0;
			int atual=0;
			if(resp==ml[a]){
				calc++;
				resp=0;
			}
			ml[a]=0;
			for(int i=1;i<=m;i++){
				if(g[a][i]==0) atual=0;
				else atual++;
				ml[a]=max(ml[a],atual);
			}
			for(int i=1;i<=n;i++) resp=max(resp,ml[i]);
			printf("%d\n", resp);
		}
		else{
			g[a][b]=1;
			int atual=0;
			for(int i=1;i<=m;i++){
				if(g[a][i]==0) atual=0;
				else atual++;
				ml[a]=max(ml[a],atual);
			}
			resp=max(resp,ml[a]);
			printf("%d\n", resp);
		}
	}
	return 0;
}		
	
	
	
	
	
	
	
	
	
	
			


