#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=112345;
const int INF=0x3f3f3f3f;

vector<int> adj[MAXN];
vector< pair<int,int> > edg;
pair<int,int> cmp[MAXN];

int marc[MAXN],resp,num,n,m;

int dfs(int x){
	marc[x]=1;
	int tam=adj[x].size();
	(cmp[num].first)++; 
	for(int h=0;h<tam;h++){
		int prox=adj[x][h];
		(cmp[num].second)++;
		if(marc[prox]==0){
			dfs(prox);
		}
	}
}

int lanc(int ini){
	cmp[num].first=0;
	cmp[num].second=0;
	dfs(ini);
	cmp[num].second/=2;
	if(cmp[num].first==(cmp[num].second+1)){
		num++;		
		return 1;
	}
	else{
		num++;
		return 0;
	}
}



int main(){
	resp=0;
	num=0;
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		edg.push_back(make_pair(a,b));
		edg.push_back(make_pair(b,a));
	}
	for(int i=1;i<=n;i++)	if(marc[i]==0) resp+=lanc(i);	
	printf("%d\n", resp);
	return 0;
}	


