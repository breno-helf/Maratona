#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)

const int MAXN=2123;
const int INF=0x3f3f3f3f;

vector<int> adj[MAXN];

int resp,n,m,marc[MAXN];

void dfs(int x){
	marc[x]=1;
	int tam=adj[x].size();
	for(int i=0;i<tam;i++){
		if(marc[adj[x][i]]==0){
			dfs(adj[x][i]);
		}
	}
}

int main(){
	while(1){
		resp=1;
		scanf("%d%d", &n, &m);
		if(n==0 && m==0) break;
		for(int i=0;i<=n;i++){
			marc[i]=0;
			adj[i].clear();
		}
		for(int i=0;i<m;i++){
			int v,w,p;
			scanf("%d%d%d", &v, &w, &p);
			adj[v].push_back(w);
			if(p==2) adj[w].push_back(v);
		}
		for(int i=1;i<=n;i++){
			dfs(i);
			for(int i=1;i<=n;i++){
				if(marc[i]==0){
					debug("Naum cheguei no %d\n", i);
					resp=0;
				}
				else marc[i]=0;
			}
		}
		debug("Resposta -->  ");
		printf("%d\n", resp);
	}
	return 0;
}

/*
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0
*/



