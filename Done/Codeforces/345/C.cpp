#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii; 

const int MAXN=212345;
const int INF=0x3f3f3f3f;

int px[MAXN],py[MAXN],n;

vector<pii> ppx,ppy;

set<pii> eq;
map<pii,int> occ;
set<pii> pont;

int main(){
	long long int resp=0;
	long long int e=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d", &px[i], &py[i]);
		ppx.pb(pii(px[i],i));
		ppy.pb(pii(py[i],i));
		if(pont.find(pii(px[i],py[i]))!=pont.end()){
			occ[pii(px[i],py[i])]++;
			e-=occ[pii(px[i],py[i])];
		}
		pont.insert(pii(px[i],py[i]));
	}
	debug("%d\n", e);
	sort(ppx.begin(),ppx.end());
	sort(ppy.begin(),ppy.end());
	int jx=0,jy=0;
	for(int i=1;i<n;i++){
		if(ppx[i].first==ppx[i-1].first){
			jx++;
		//	if(eq.find(pii(ppx[i].second,ppx[i-1].second))==eq.end()){
				resp+=jx;
				debug("Somei %d -- Liguei o par (%d,%d) ~ em x\n", jx, ppx[i].second, ppx[i-1].second); 
		//		for(int k=0;k<=jx;k++){
			//		for(int h=0;h<=jx;h++){
					//if(k==h+1) continue;
		//				eq.insert(pii(ppx[i].second,ppx[i-1].second));
		//				eq.insert(pii(ppx[i-1].second,ppx[i].second));
		//			}
	//			}
	//		}
	//		else jx=0;
		}
		else jx=0;
		if(ppy[i].first==ppy[i-1].first){
			jy++;
		//	if(eq.find(pii(ppy[i].second,ppy[i-1].second))==eq.end()){
				resp+=jy;
				debug("Somei %d -- Liguei o par (%d,%d) ~ em y\n", jy, ppy[i].second, ppy[i-1].second);
		//		for(int k=0;k<=jy;k++){
			//		for(int h=0;h<=jy;h++){
				//		if(k==h+1) continue;
		//				eq.insert(pii(ppy[i].second,ppy[i-1].second));
		//				eq.insert(pii(ppy[i-1].second,ppy[i].second));
		//			}
		//		}
		//	}
		//	else jy=0;
		}
		else jy=0;
	}
	resp+=e;
	if(resp<0) resp=0;
	printf("%I64d\n", resp);
	return 0;
}



