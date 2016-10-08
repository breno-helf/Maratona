//This code was made by Breno Moura, Codeforces Handle: Brelf
//From University of São Paulo - USP
//If you are trying to hack me I wish you can get it, Good Luck :D
#include<bits/stdc++.h>
using namespace std;

#define debug(args...) //fprintf(stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN=1123;
const int INF=0x3f3f3f3f;
const ll  MOD=1000000007;

string in, out, ex, resp;
int e, pos, tam, st;

int main() {
    cin >> in;
    pos = 0;
    tam = in.size();
    ex = resp = out = "";
    while(in[pos] != 'e') pos++;
    for(int i = pos + 1; i < tam; i++)
        ex += in[i];
    e = stoi(ex, nullptr);
    for(int i = 0; i < pos; i++)
        out += in[i];

    int sw = 0;
    for(int i = 2; (sw < e) && (i < pos); i++) {
        swap(out[i - 1], out[i]);
        sw++;
    }

    if((e + 2 >= pos)) {
        in = "";
        for(int i = 0; i < (pos - 1); i++) {
            in += out[i];
        }
        out = in;
        for(int i = pos; i < (e+2); i++) out += '0';
    }
    st = e;
    //cout << "--> " << out << '\n';
    
    for(int i = 0; i < (e + 1); i++) {
        if(out[i] != '0') {
            st = i;
            break;
        }
    }
    for(int i = st; i < (e + 1); i++)
        resp += out[i];

    st = e;
    for(int i = ((int)out.size() - 1); i >= (e + 2); i--)
        if(out[i] != '0') {
            st = i;
            break;
        }
    
    for(int i = (e + 1); i <= st; i++)
        resp += out[i];
    cout << resp << '\n';
}

            
