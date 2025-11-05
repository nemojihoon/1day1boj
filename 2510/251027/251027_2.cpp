//11108 weighted interval
#include <iostream>
#include <vector>
using namespace std;

int t, test, n, s, d, p;
vector<vector<pair<int, int>>> tv;
vector<int> dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> test;
    for(int t = 0; t < test; t++) {
        cin >> n;
        tv.resize(10081);
        int mat = 0;
        for(int i = 0; i < n; i++) {
            cin >> s >> d >> p;
            tv[s+d].push_back({s, p});
            mat = max(mat, s+d);
        }
        dp.resize(mat+1);
        for(int i = 1; i <= mat; i++) {
            dp[i] = dp[i-1];
            for(auto pro:tv[i]) {
                dp[i] = max(dp[i], dp[pro.first]+pro.second);
            }
        }
        cout << dp[mat] << endl;
        dp.clear();
        tv.clear();
    }


    return 0;
}