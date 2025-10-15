//1106 dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int c, n, cost, inc, maxInc;
int dp[1300];
vector<pair<int, int>> city;

int main() {
    cin >> c >> n;
    for(int i = 0; i < n; i++) {
        cin >> cost >> inc;
        city.push_back({cost, inc});
        maxInc = max(maxInc, inc);
    }

    fill(dp, dp+1300, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < c; i++) {
        if(dp[i] == INT_MAX) continue;
        for(int j = 0; j < n; j++) {
            dp[i + city[j].second] = min(dp[i + city[j].second], dp[i] + city[j].first);
        }
    }

    cout << *min_element(dp + c, dp + c + maxInc);
    return 0;
}