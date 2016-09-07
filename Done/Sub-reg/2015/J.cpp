#include<bits/stdc++.h>
#define dbg(args...) fprintf(stderr, args)
#define m(x) memset((x), 0, sizeof(x))
using namespace std;

const int MAXN = 212345;
const int INF = 0x3f3f3f3f;

const int MAXJ = 512;
const int MAXR = 512;

int v[MAXJ*MAXR];
int jog[MAXJ];
int maxponto;
int vencedor;

int main(){
    int j,r;
    while(cin >> j >> r){
        m(jog);
        m(v);
        maxponto = 0;
        vencedor = 0;
        
        for(int i=0; i<j*r; i++){
            cin >> v[i];        
        }
        
        for(int i=0; i<j*r; i++){
            jog[i%j] += v[i];
            dbg("m %d\n", maxponto);
            if(jog[i%j] >= maxponto){
                
                maxponto = jog[i%j];
                vencedor = i%j;
                //dbg("v %d\n", vencedor);
            }
        }
        
        cout << vencedor + 1 << endl;
    }
}
