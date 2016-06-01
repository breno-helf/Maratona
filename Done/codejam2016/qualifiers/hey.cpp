#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=1123456;
const int INF=0x3f3f3f3f;

ll n, aux;
set<int> seen;
int t;


int main(){
	scanf("%d", &t);
	for(int tt=1;tt<=t;tt++){
		scanf("%lld", &n);
		if(n==0){
			printf("Case #%d: INSOMNIA\n", tt);
			continue;
		}
		int i=1;
		while(1){
			aux=n*i;
			do{
				int digito=aux%10;
				seen.insert(digito);
				aux/=10;
			}while(aux>0);
			if((seen.size())==10) break;
			i++;
		}
		n*=i;
		printf("Case #%d: %lld\n", tt, n);
		seen.clear();
	}
	return 0;
}
