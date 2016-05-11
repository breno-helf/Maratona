#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

int pai[MAXN],u[MAXN],h[MAXN],q[MAXN],m,marc[MAXN],ad[2]={-1,1},resp[MAXN],d,n;
pii ord[MAXN];

int raiz(int a){
	if(pai[a]==a) return a;
	else return pai[a]=raiz(pai[a]);
}

int une(int a, int b){
	a=raiz(a);
	b=raiz(b);
	if(a==b) return 0;
	if(u[b]>u[a]) swap(a,b);
	if(u[a]==u[b]) u[a]++;
	pai[b]=a;
	return 1;
}

bool find(int a, int b){
	if(raiz(a)==raiz(b)) return 1;
	else return 0;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int tt=0;tt<t;tt++){
		memset(u,0,sizeof(u));
		memset(pai,0,sizeof(pai));
		memset(h,0,sizeof(h));
		memset(q,0,sizeof(q));
		memset(marc,0,sizeof(marc));
		memset(resp,0,sizeof(resp));
		memset(ord,0,sizeof(ord));
		scanf("%d%d", &n, &d);
		for(int i=0;i<n;i++){
			scanf("%d", &h[i]);
			ord[i].first=h[i];
			ord[i].second=i;
			pai[i]=i;
		}
		sort(ord,ord+n);
		m=n-1;
		int num=0;
		for(int i=0;i<d;i++)	scanf("%d", &q[i]);
		for(int i=d-1;i>=0;i--){
			if(i<d-1) resp[i]=resp[i+1];
			while(ord[m].first>q[i]){
				resp[i]++;
				marc[ord[m].second]=1;
				for(int g=0;g<2;g++){
					if((ord[m].second+ad[g])<n && (ord[m].second+ad[g])>=0){
						if(marc[ord[m].second+ad[g]]==1)	resp[i]-=une(ord[m].second+ad[g],ord[m].second);
					}
				}
				m--;
			}
			
		}
		for(int i=0;i<d-1;i++) printf("%d ", resp[i]);
		printf("%d\n", resp[d-1]);
	}
	return 0;
}






