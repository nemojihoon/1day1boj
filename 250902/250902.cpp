//11108 dp
#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;
using std::pair;

int test, n, s, d, p, mat;
vector<int> dp(10085);
vector<vector<pair<int, int>>> tv(10085);

int main() {
    cin >> test;

    for(int t = 0; t < test; t++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s >> d >> p;
            tv[s+d].push_back({s, p});
            mat = max(mat, s+d);
        }

        for(int i = 1; i <= mat; i++) {
            dp[i] = dp[i-1];
            if(!tv[i].empty()) {
                for(auto pro:tv[i]) {
                    dp[i] = max(dp[i], dp[pro.first] + pro.second);
                }
            }
        }

        cout << dp[mat] << "\n";
        tv.clear();
        tv.resize(10085);
        dp.clear();
        dp.resize(10085);
        mat = 0;
        n = 0;
    }
}