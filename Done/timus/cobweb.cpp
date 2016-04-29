#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int pai[MAXN],n,m,h[MAXN],marc[MAXN],corta[MAXN],junt[MAXN][2],q,resp[MAXN];

set<int> s;


int raiz(int x){
	if(pai[x]==x) return x;
	else return pai[x]=raiz(pai[x]);
}

void une(int a, int b){
	a=raiz(a);
	b=raiz(b);
	if(h[a]<h[b]) swap(a,b);
	if(h[a]==h[b]) h[a]++;
	pai[b]=a;
}

int ver(int a, int b){
	if(raiz(a)==raiz(b)) return 1;
	else return 0;
}

int main(){
	scanf("%d%d", &n, &m);
	memset(h,1,sizeof(h));
	for(int i=1;i<=n;i++) pai[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d", &a, &b);
		junt[i][0]=a;
		junt[i][1]=b;
	}
	scanf("%d", &q);
	for(int i=1;i<=q;i++){
		scanf("%d", &corta[i]);
		marc[corta[i]]=1;
	}
	for(int i=1;i<=m;i++)	if(marc[i]==0)	une(junt[i][0],junt[i][1]);
	//debug("1 e 2 estão %d\n", ver(1,2));
	for(int k=1;k<=n;k++) s.insert(raiz(k));
	for(int i=q;i>0;i--){
		int apa,apb;
		resp[i]=s.size();
		apa=raiz(junt[corta[i]][0]);
		apb=raiz(junt[corta[i]][1]);		
		une(junt[corta[i]][0],junt[corta[i]][1]);
		if(apa!=raiz(junt[corta[i]][0]))	s.erase(apa);
		if(apb!=raiz(junt[corta[i]][1]))	s.erase(apb);
	}
	for(int i=1;i<q;i++) printf("%d ", resp[i]);
	printf("%d\n", resp[q]);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
