#include <bits/stdc++.h>

using namespace std;

int main(){
    int h1, m1, h2, m2;
    
    while(cin >> h1 >> m1 >> h2 >> m2 && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0)){
        int ans = 0;
    
        if(h1 == 0) h1 += 24;
        if(h2 == 0) h2 += 24;
        
        if(h2 > h1){
            ans = ((h2-h1)*60+m2)-m1;
        } else if(h2 == h1) {
            if(m2>m1){
                ans = m2 - m1;
            } else if(m2 == m1){
                ans = 0;
            } else if(m2 < m1){
                ans = 1440 - (m1 - m2);
            }
        } else if(h2 < h1){
            ans = 1440 - (((h1-h2)*60+m1)-m2);
        }
        
        cout << ans << endl;
    }
}
