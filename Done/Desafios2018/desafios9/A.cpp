#include<bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr, args)

int n;
map<int, int> M;
int cnt = 0;

int main() {
    ifstream cin("homo.in");
    ofstream cout("homo.out");
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int num;
        cin >> s >> num;

        if (s == "insert") {
            M[num]++;
            if (M[num] == 2) cnt++;
        } else {
            if (M.find(num) != M.end()) {
                M[num]--;

                if (M[num] == 1) cnt--;

                if (M[num] == 0) {
                    //debug("Tried to delete key %d\n", num);
                    M.erase(num);
                }
            }
        }

        // debug("(%s %d) -- My map is\n", s.c_str(), num);
        // for (auto e : M) {
        //     debug("--> %d %d\n", e.first, e.second);            
        // }
        // debug("\n");
        
        if ((int)M.size() > 1 && cnt > 0) {
            cout << "both" << '\n';
        } else if (cnt > 0) {
            cout << "homo" << '\n';
        } else if ((int)M.size() > 1) {
            cout << "hetero" << '\n';
        } else {
            cout << "neither" << '\n';
        }

        //debug("\n");
    }

    return 0;
}
