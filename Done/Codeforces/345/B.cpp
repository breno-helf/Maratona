#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;


int v[MAXN],n,resp,p[MAXN],alt,maxj;

vector<int> prox[MAXN];

int main(){
	resp=0;
	maxj=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &v[i]);
//		prox[i].pb(v[i]);
		p[v[i]]++;
	}
//	sort(&v[0], &v[n]);
//	for(int i=1;i<n;i++)	if(v[i]>v[i-1]) resp++;
	for(int i=1;i<=1000;i++){
		int j=0;
		while(p[i]>0){
			prox[j].pb(i);
			j++;
			p[i]--;
		}
		maxj=max(j,maxj);
	}
	for(int i=0;i<maxj;i++){
		sort(prox[i].begin(),prox[i].end());
		int tam=prox[i].size();
		for(int k=1;k<tam;k++)	if(prox[i][k]>prox[i][k-1]) resp++;
	}
	printf("%d\n", resp);
	return 0;
}

