#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr, args) 

const int MAXN=900;
const int INF=0x3f3f3f3f;

set< pair< int, pair<int,int> > > s;

int n,m[MAXN][MAXN],mark[MAXN][MAXN];
int dist[MAXN][MAXN];
char c;

int func(int q, int w){
	if((q-w)<0) return q-w+4;
	else return q-w;
}

void bfs(int a, int b){

	s.insert(make_pair(0,make_pair(a,b)));
	dist[0][0]=0;
	while(!s.empty()){
		int x=((s.begin())->second.first)/n;
		int y=((s.begin())->second.first)%n;
		int dir=(s.begin())->second.second;
		int robs=(s.begin())->first;
		if(x==n-1 && y==n-1){
			if(dir!=0){
				s.erase(make_pair(robs,make_pair((x)*(n)+y,dir)));
				dist[x][y]+=func(0,dir);
				s.insert(make_pair(dist[x][y],make_pair((x)*(n)+y,0)));
				continue;
			}
			else break;	
		}
		debug("x eh %d\ny eh %d\ndir eh %d\nrobs eh %d\n", x, y, dir,robs);
		mark[x][y]=1;
		if(x>0){
			if((dist[x][y]+1+func(2,dir))<dist[x-1][y] && m[x-1][y]==0){
				if(mark[x-1][y]==0 && dist[x-1][y]!=INF){
					s.erase(make_pair(dist[x-1][y],make_pair((x-1)*(n)+y,2)));
					dist[x-1][y]=dist[x][y]+1+func(2,dir);
					s.insert(make_pair(dist[x-1][y],make_pair((x-1)*(n)+y,2)));
					debug("Tirei e recoloquei com valor %d a posição [%d][%d]\n", dist[x-1][y], x-1, y);
				}
				else{
					dist[x-1][y]=dist[x][y]+1+func(2,dir);
					s.insert(make_pair(dist[x-1][y],make_pair((x-1)*(n)+y,2)));
					debug("1 Coloquei o valor %d na posição [%d][%d]\n", dist[x-1][y], x-1, y);
				}
			}
		}
		if(y>0){
			if((dist[x][y]+1+func(3,dir))<dist[x][y-1] && m[x][y-1]==0){
				if(mark[x][y-1]==0 && dist[x][y-1]!=INF){
					s.erase(make_pair(dist[x][y-1],make_pair((x)*(n)+y-1,3)));
					dist[x][y-1]=dist[x][y]+1+func(3,dir);
					s.insert(make_pair(dist[x][y-1],make_pair((x)*(n)+y-1,3)));
					debug("Tirei e recoloquei com valor %d a posição [%d][%d]\n", dist[x][y-1], x, y-1);
				}
				else{
					dist[x][y-1]=dist[x][y]+1+func(3,dir);
					s.insert(make_pair(dist[x][y-1],make_pair((x)*(n)+y-1,3)));
					debug("2 Coloquei o valor %d na posição [%d][%d]\n", dist[x][y-1], x, y-1);
				}
			}
		}		
	 	if(y<n-1){
			if((dist[x][y]+1+func(1,dir))<dist[x][y+1] && m[x][y+1]==0){
				if(mark[x][y+1]==0 && dist[x][y+1]!=INF){
					s.erase(make_pair(dist[x][y+1],make_pair((x)*(n)+y+1,1)));
					dist[x][y+1]=dist[x][y]+1+func(1,dir);
					s.insert(make_pair(dist[x][y+1],make_pair((x)*(n)+y+1,1)));
					debug("Tirei e recoloquei com valor %d a posição [%d][%d]\n", dist[x][y+1], x, y+1);
				}
				else{
					dist[x][y+1]=dist[x][y]+1+func(1,dir);
					s.insert(make_pair(dist[x][y+1],make_pair((x)*(n)+y+1,1)));
					debug("3 Coloquei o valor %d na posição [%d][%d]\n", dist[x][y+1], x, y+1);
				}
			}
		}
		if(x<n-1){
			if((dist[x][y]+1+func(0,dir))<dist[x+1][y] && m[x+1][y]==0){
				if(mark[x+1][y]==0 && dist[x+1][y]!=INF){
					s.erase(make_pair(dist[x+1][y],make_pair((x+1)*(n)+y,0)));
					dist[x+1][y]=dist[x][y]+1+func(0,dir);
					s.insert(make_pair(dist[x+1][y],make_pair((x+1)*(n)+y,0)));
					debug("Tirei e recoloquei com valor %d a posição [%d][%d]\n", dist[x+1][y], x+1, y);	
				}
				else{
					dist[x+1][y]=dist[x][y]+1+func(0,dir);
					s.insert(make_pair(dist[x+1][y],make_pair((x+1)*(n)+y,0)));
					debug("4 Coloquei o valor %d na posição [%d][%d]\n", dist[x+1][y], x+1, y);
				//	break;
				}
			}
		}
		s.erase(make_pair(robs,make_pair((x)*(n)+y,dir)));
		debug("Apaguei [%d][%d] que tinha dir %d e robs eh %d\n", x,y,dir,robs);
	}

}


int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			scanf(" %c", &c);
			if(c=='#')	m[i][k]=1;
			dist[i][k]=INF;
		}
	}
	debug("\nGRID\n");
	for(int i=0;i<n;i++){
		debug("\n");
		for(int k=0;k<n;k++){
			debug(" %d", m[i][k]); 
		}
	}
	debug("\n");
	bfs(0,0);
	printf("%d\n", dist[n-1][n-1]);
	return 0;
}	
