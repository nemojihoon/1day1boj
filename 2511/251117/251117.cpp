//11108 weighted interval scheduling
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int test, n, s, d, p;
struct Program {
    int s, e, w;
};
vector<Program> programs;
vector<int> prior, dp;

bool cmp(const Program &a, const Program &b) {
    if(a.e != b.e) return a.e < b.e;
    else return a.s < b.s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> test;
    for(int t = 0; t < test; t++) {
        cin >> n; 
        programs.resize(n+1);
        prior.resize(n+1); dp.resize(n+1);
        prior[0] = 0; dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> s >> d >> p;
            programs[i] = {s, s+d, p};
        }
        sort(programs.begin()+1, programs.end(), cmp);
        for(int i = 1; i <= n; i++) {
            prior[i] = (upper_bound(programs.begin(), programs.end(), programs[i].s, 
                            [](int value, const Program &prog) {
                                return value < prog.e;
                            }) - programs.begin()) - 1;
        }
        for(int i = 1; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[prior[i]] + programs[i].w);
        }
        cout << dp[n] << '\n';
        programs.clear();
        prior.clear();
        dp.clear();
    }

    return 0;
}