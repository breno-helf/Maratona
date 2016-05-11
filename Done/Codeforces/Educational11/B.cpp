#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;


int fila[MAXN][4],n,ini[4],fim[4],m,d[4]={3,1,0,2};


int main(){
	scanf("%d%d", &n, &m);
	int tam1,tam2;
	memset(fila,0,sizeof(fila));
	memset(ini,0,sizeof(ini));
	memset(fim,0,sizeof(fim));
	if(m>=2*n) tam1=2*n;
	else tam1=m;
	tam2=tam1+m-2*n;
	for(int i=1;i<=tam1;i++){
		if(i%2==1){
			fila[fim[0]++][0]=i;
		}
		else fila[fim[3]++][3]=i;
	}
	for(int i=tam1+1;i<=tam2;i++){
		if(i%2==1){
			fila[fim[1]++][1]=i;
		}
		else fila[fim[2]++][2]=i;
	}
	debug("\n");
	for(int i=1;i<=m;i++){
		//debug("%d ", d[i%4]);
		while(fila[ini[d[i%4]]][d[i%4]]==0){
			i++;
			m++;
		}
		if(i!=m)	printf("%d ", fila[ini[d[i%4]]][d[i%4]]);
		else	printf("%d\n", fila[ini[d[m%4]]][d[m%4]]);
		ini[d[i%4]]++;
	}
	//printf("%d\n", fila[ini[d[m%4]]][d[m%4]]);
	return 0;
}





