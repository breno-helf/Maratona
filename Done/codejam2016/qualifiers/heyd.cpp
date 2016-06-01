#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)
#define pb push_back;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=112;
const int INF=0x3f3f3f3f;

int k,c,s,t;



int main(){
	scanf("%d", &t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d%d%d", &k, &c, &s);
		if(k==s){
			printf("Case #%d: ", tt); 
			for(int i=1;i<k;i++)	printf("%d ", i);
			printf("%d\n", k);
		}		
	}
	return 0;
}
