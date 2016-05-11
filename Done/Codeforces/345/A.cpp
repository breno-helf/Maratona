#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=11234;
const int INF=0x3f3f3f3f;


int a,b;


int main(){
	int resp=0;
	scanf("%d%d", &a, &b);
	while(a>0 && b>0){
		if(a<b){
			a++;
			b-=2;
			if(b<0) break;
			resp++;
		}
		else{
			b++;
			a-=2;
			if(a<0) break;
			resp++;
		}			
	}
	printf("%d\n", resp);
	return 0;
}
