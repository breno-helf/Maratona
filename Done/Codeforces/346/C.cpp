#include<bits/stdc++.h>
using namespace std;

const int MAXN=112345;
const int INF=0x3f3f3f3f;

int num,dp,n,m,t[MAXN],din;

vector<int> resp;

void faz(){
	dp=0;
	for(int i=1;i<=din;i++){
		if(t[i]==0 && din-i>=0){
			dp++;
			din-=i;
			resp.push_back(i);
		}
	}
}			
			

int main(){
	scanf("%d%d", &n, &m);
	din=m;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d", &a);
		t[a]=1;
	}
	faz();
	printf("%d\n", dp);
	int tam=resp.size();
	for(int i=0;i<tam-1;i++)	printf("%d ", resp[i]);
	printf("%d\n", resp[tam-1]);
//	printf("\n");
	return 0;
}



