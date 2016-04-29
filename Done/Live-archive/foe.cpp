#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=312345;
const int INF=0x3f3f3f3f;

typedef long long int ll;

int n,m,v[MAXN],ind[MAXN];
vector<int> q[MAXN];

ll resp;


int main(){
	scanf("%d%d", &n, &m);
	resp=0;
	for(int i=1;i<=n;i++){
		scanf("%d", &v[i]);
		ind[v[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		a=ind[a];
		b=ind[b];
		if(a>b) swap(a,b);
		q[a].push_back(b);	
	}	
	int mine=n+1;
	for(int i=n;i>=1;i--){	
		int tam=q[i].size();
		for(int j=0;j<tam;j++) mine=min(mine,q[i][j]);
		resp+=mine-i;
	}
	printf("%lld\n", resp);
	return 0;
}	
	
	
	
	
	
	
	
