#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112345678;
const int INF=0x3f3f3f3f;

int t,n,j,p;
ll jam;
ll b[15];
ll resp[15];
int primo(ll num, int e){
	for(ll k=2;k*k<num;k++){	
		if(num%k==0){
			resp[e]=k;
			return 0;
		}
	}	
	return 1;
}

ll fst(ll a, ll n){
	ll resp=1;
	for(int i=0;i<63;i++){
		if((a&(1ll<<i))>0) resp*=n;
		n*=n;
	}
	return resp;	
}

int main(){
	scanf("%d", &t);
		p=0;
		scanf("%d%d", &n, &j);
		ll tam=(1ll<<n);
		printf("Case #1:\n");
		for(ll i=0;i<tam;i++){
			int pula=0;
			memset(resp,0,sizeof(resp));
			memset(b,0,sizeof(b));
			if((i%2)==0) continue;
			int aux=i;
			for(int k=2;k<=10;k++) b[k]+=fst(n,k);
			for(int k=0;k<n;k++){
				if(aux&(1ll<<k))	for(int k=2;k<=10;k++) b[k]+=fst(n,k);
			}
			for(int x=2;x<=10;x++){
				if(primo(b[x],x)==1){
					pula++;
					break;
				}
			}
			if(pula) continue;
			p++;
			printf("1");
			for(int k=n-2;k>0;k--){
				if(i&(1ll<<k)) printf("1");
				else printf("0");
			}
			printf("1 ");
			for(int k=2;k<10;k++)	printf("%lld ", resp[k]);
			printf("%lld\n", resp[10]);
			if(p==j) break;
	}
	return 0;
}
