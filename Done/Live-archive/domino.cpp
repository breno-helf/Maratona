#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

vector<int> adj[MAXN],toposort;

int t,p,marc[MAXN],n,m,chama[MAXN];

void dfs(int x){
	marc[x]=1;
	int tam=adj[x].size();
	for(int i=0;i<tam;i++){
		if(marc[adj[x][i]]==0)	dfs(adj[x][i]);
//		else if(resp[adj[x][i]]==1) resp[adj[x][i]]=0;
	}
	toposort.push_back(x);
}

int main(){
	scanf("%d", &t);
	for(int k=0;k<t;k++){
		scanf("%d%d", &n, &m);
		p=0;
		for(int i=0;i<=n;i++){
			chama[i]=0;
			marc[i]=0;
		//	resp[i]=0;
			adj[i].clear();
		}
		toposort.clear();
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
		}
		for(int i=1;i<=n;i++){
			if(marc[i]==0){
				dfs(i);
			}
		}
		for(int i=0;i<=n;i++){
			marc[i]=0;
		//	if(i<n)	chama[n-1]=toposort[i];
		}
		int h=toposort.size();
		for(int i=h-1;i>=0;i--){
			if(marc[toposort[i]]==0){
				dfs(toposort[i]);
				p++;
			}
		}
		printf("%d\n", p);
	}
	return 0;
}	
