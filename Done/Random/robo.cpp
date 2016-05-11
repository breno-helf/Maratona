#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;

#define debug(args...) //fprintf(stderr, args) 

const int MAXN=212;
const int INF=0x3f3f3f3f;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};


//        dir
//        x + dx[dir];
//        y + dy[dir];

//      dist[x+dx[dir]][y+dy[dir]][dir]; // andar pra frente
///     dist[x][y][(dir+1)%4];      // girar pra esquerda


int n,dist[MAXN][MAXN][4],marc[MAXN][MAXN][4],fila[512345][3],ini,fim,m[MAXN][MAXN];
char c;

void bfs(){
	ini=0;
	fim=0;
	fila[fim][0]=0;
	fila[fim][1]=0;
	fila[fim++][2]=0;
	dist[0][0][0]=0;
	marc[0][0][0]=1;
	while(fim!=ini){
		int x=fila[ini][0];
		int y=fila[ini][1];
		int dir=fila[ini][2];
		debug("Acessei %d %d olhando para %d, sua dist é %d\n", x, y, dir, dist[x][y][dir]);
		if((x+dx[dir])>=0 && (x+dx[dir])<=n-1 && (y+dy[dir])>=0 && (y+dy[dir])<=n-1){
			if(m[x+dx[dir]][y+dy[dir]]==0){
				if(marc[x+dx[dir]][y+dy[dir]][dir]==0){
				dist[x+dx[dir]][y+dy[dir]][dir]=dist[x][y][dir]+1;
				fila[fim][0]=x+dx[dir];
				fila[fim][1]=y+dy[dir];
				fila[fim++][2]=dir;
				marc[x+dx[dir]][y+dy[dir]][dir]=1;
				}
				else if(dist[x][y][dir]+1<dist[x+dx[dir]][y+dy[dir]][dir]){
					dist[x+dx[dir]][y+dy[dir]][dir]=dist[x][y][dir]+1;
					fila[fim][0]=x+dx[dir];
					fila[fim][1]=y+dy[dir];
					fila[fim++][2]=dir;
				}
			}
		}
		if(marc[x][y][(dir+1)%4]==0){
			dist[x][y][(dir+1)%4]=dist[x][y][dir]+1;
			fila[fim][0]=x;
			fila[fim][1]=y;
			fila[fim++][2]=(dir+1)%4;
			marc[x][y][(dir+1)%4]=1;
		}
		else if(dist[x][y][dir]+1<dist[x][y][(dir+1)%4]){
			dist[x+dx[dir]][y+dy[dir]][dir]=dist[x][y][dir]+1;
			fila[fim][0]=x+dx[dir];
			fila[fim][1]=y+dy[dir];
			fila[fim++][2]=dir;
		}
		ini++;
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			scanf(" %c", &c);
			if(c=='#') m[i][k]=1;
			for(int a=0;a<4;a++) dist[i][k][a]=INF;
		}
	}
	bfs();
	printf("%d\n", dist[n-1][n-1][0]);
	return 0;
}	
