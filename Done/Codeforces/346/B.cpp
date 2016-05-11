#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

const int MAXN=112345;
const int INF=0x3f3f3f3f;



int n,m,p[MAXN];

vector<int> reg[MAXN];

char sur[MAXN][15];

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		int a;
		scanf("%s ", sur[i]);
		scanf("%d", &a);
		reg[a].push_back(i);
		scanf("%d", &p[i]);
	}
	for(int i=1;i<=m;i++){
		int tam=reg[i].size();
		int max1=-1,max2=-1,max3=-1,ind1,ind2;
		for(int k=0;k<tam;k++){
			int w=reg[i][k];
			if(p[w]>max1){
				max3=max2;
				max2=max1;
				ind2=ind1;
				max1=p[w];
				ind1=w;
			}
			else if(p[w]>max2){
				max3=max2;
				max2=p[w];
				ind2=w;
			}
			else if(p[w]>max3) max3=p[w];
		}
		if(max2==max3) printf("?\n");
		else{
			printf("%s ", sur[ind1]);
			printf("%s\n", sur[ind2]);
		}
	}
	return 0;
}	
