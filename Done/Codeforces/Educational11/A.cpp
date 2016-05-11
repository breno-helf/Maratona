#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n,v[MAXN],resp[2*MAXN],adj[MAXN],nresp;
int tamr;

int mdc(int a, int b){
	while(a>0 && b>0){
		int aux;
		aux=b;
		b=a%b;
		a=aux;
	}
	return a;
}

int main(){

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &v[i]);
		int a=v[i];	
	}
	resp[0]=v[0];
	tamr=1;
	for(int i=1;i<n;i++){
		if(mdc(v[i-1],v[i])>1){
			resp[tamr++]=1;
			resp[tamr++]=v[i];
		}
		else resp[tamr++]=v[i];
	}
	printf("%d\n", tamr-n);
	for(int i=0;i<tamr-1;i++){
		printf("%d ", resp[i]);
	}	
	printf("%d\n", resp[tamr-1]);
	return 0;
}
