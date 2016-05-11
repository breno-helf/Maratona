#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;

int v,e;

vector< pair<int,int> > adj[MAXN];

int dist[MAXN][2],fila[11234567][2],ini,fim,marc[MAXN][2];


int bfs(){
	ini=0;
	fim=0;
	fila[fim][0]=1;
	fila[fim++][1]=0;
	marc[1][0]=1;
	marc[1][1]=0;
	dist[1][0]=0;
	dist[1][1]=INF;
	while(ini!=fim){
		int a=fila[ini][0],b,c;
		int p=fila[ini][1];
		int tam=adj[a].size();
		//debug("Entrei no vertice %d\n", a);
		for(int i=0;i<tam;i++){
			//debug("Dist de a eh %d\n", dist[a][0]);
			b=adj[a][i].first;
			c=adj[a][i].second;
			if((p%2)!=0){
				if(marc[b][0]==0 || dist[a][1]+c<dist[b][0]){
					dist[b][0]=min(dist[b][0],dist[a][1]+c);
					fila[fim][0]=b;
					fila[fim++][1]=(p+1)%2;
					marc[b][0]=1;
				}
			}
			if((p%2)==0){
				if(marc[b][1]==0 || dist[a][0]+c<dist[b][1]){
					dist[b][1]=min(dist[b][1],dist[a][0]+c);
					fila[fim][0]=b;
					fila[fim++][1]=(p+1)%2;
					marc[b][1]=1;
				}
			}
		}
		ini++;
	}
	if(dist[v][0]!=INF) return dist[v][0];
	else return -1;
}



int main(){
	memset(dist,INF,sizeof(dist));
	scanf("%d%d", &v, &e);
	for(int i=0;i<e;i++){
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	printf("%d\n", bfs());
	return 0;
}
