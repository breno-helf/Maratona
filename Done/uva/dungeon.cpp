#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)

const int MAXN=50;
const int INF=0x3f3f3f3f;

char a;

int m[MAXN][MAXN][MAXN],l,r,c,ini,fim,fila[112345][3];
int marc[MAXN][MAXN][MAXN],dist[MAXN][MAXN][MAXN];
int dx[6]={0,1,0,-1,0,0},dy[6]={1,0,-1,0,0,0};
int dz[6]={0,0,0,0,1,-1},start[5],end[5];

int bfs(int x, int y, int z){
	//debug("Entrei\n");
	dist[x][y][z]=0;
	marc[x][y][z]=1;
	ini=0;
	fim=0;
	fila[fim][0]=x;
	fila[fim][1]=y;
	fila[fim++][2]=z;
	//debug("Mais perto\n");
	while(ini!=fim){
		int f=fila[ini][0];
		int g=fila[ini][1];
		int h=fila[ini][2];
		debug("Analisando %d %d %d\n\n", f, g, h);
		for(int i=0;i<6;i++){
			debug("Olhei [%d][%d][%d] \n", f+dx[i], g+dy[i], h+dz[i]);
			if((f+dx[i])>=0 && (f+dx[i])<l && (g+dy[i])>=0 && (g+dy[i])<r && (h+dz[i])>=0 && (h+dz[i])<c){
				debug("Essa posicao eh valida =D\n");
				if(m[f+dx[i]][g+dy[i]][h+dz[i]]==0 && marc[f+dx[i]][g+dy[i]][h+dz[i]]==0){
					debug(" Foi inserida na fila\n");
					dist[f + dx[i]][g + dy[i]][h + dz[i]] =
                  dist[f][g][h] + 1;
					fila[fim][0]=f+dx[i];
					fila[fim][1]=g+dy[i];
					fila[fim++][2]=h+dz[i];
					marc[f+dx[i]][g+dy[i]][h+dz[i]]=1;
				}
			}
		}
		ini++;
	}
	//debug("Aqui?\n");
	if(dist[end[0]][end[1]][end[2]]==INF) return -1;
	else return dist[end[0]][end[1]][end[2]];
}

int main(){
	while(1){
		scanf("%d%d%d", &l, &r, &c);
		if(l==0 && r==0 && c==0) break;
		memset(m,0,sizeof(m));
		memset(marc,0,sizeof(marc));
		memset(dist,INF,sizeof(dist));
		for(int i=0;i<l;i++){
			for(int j=0;j<r;j++){
				for(int k=0;k<c;k++){
					scanf(" %c", &a);
					if(a=='#') m[i][j][k]=1;
					if(a=='S' || a=='s'){
						start[0]=i;
						start[1]=j;
						start[2]=k;
					}
					if(a=='E' || a=='e'){
						end[0]=i;
						end[1]=j;	
						end[2]=k;
					}
				}
			}
		}
		if(bfs(start[0],start[1],start[2])==-1) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", dist[end[0]][end[1]][end[2]]);
	}
	return 0;
}				
					
					
					
					
					
