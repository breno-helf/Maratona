//If you are trying to hack me I wish you can get it, Good Luck :D.
#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf (stderr,args)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX = 1e3 + 10;

int minSalary[MAX];
int offeredSalary[MAX];
int maxJobOffers[MAX];
vector<int> offer[MAX];
int taken[MAX];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for (int i = 1; i <= n; i++) {
            scanf("%d", &minSalary[i]);
        }

        vector<pii> company;
        
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &offeredSalary[i], &maxJobOffers[i]);
            company.push_back(pii(offeredSalary[i], i));
        }

        sort(company.begin(), company.end());
        reverse(company.begin(), company.end());
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char qualified;
                scanf(" %c", &qualified);
                //debug("%c", qualified);
                if (qualified == '1' && maxJobOffers[j] > 0) {
                    offer[j].push_back(i);
                }
            }
            //debug("\n");
        }

        int gotJob = 0;
        ll totalSalary = 0;
        int badCompanies = m;
        
        for (pii e : company) {
            int salary = e.first;
            int j = e.second;
            bool gotOne = false;
            for (int i : offer[j]) {
                if (taken[i] == 0 && minSalary[i] <= salary) {
                    //debug("Candidate %d got job %d\n", i, j);
                    taken[i] = 1;
                    totalSalary += (ll)salary;
                    gotJob++;
                    maxJobOffers[j]--;
                    gotOne = true;

                    if (maxJobOffers[j] == 0) break;
                }
            }
            if (gotOne == true) badCompanies--;
        }
        
        printf("%d %lld %d\n", gotJob, totalSalary, badCompanies);

        for (int i = 1; i <= max(n, m); i++) {
            taken[i] = 0;
            offer[i].clear();
        }
        
    }
    
}


