#include<bits/stdc++.h>
using namespace std;

const int MAXN=1123;
const int INF=0x3f3f3f3f;

int n,a,b,resp,e;

int main(){
	scanf("%d%d%d", &n, &a, &b);
	resp=a;
	e=0;
	if(b<0){
		e=1;
		b*=-1;
	}	
	for(int i=1;i<=b;i++){
		if(e) resp--;
		else resp++;
		if(resp>n) resp=1;
		if(resp<1) resp=n;
	}
	printf("%d\n", resp);
	return 0;
}

