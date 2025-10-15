//2294 dp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> coin;
    coin.reserve(n);
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        if (c <= k) coin.push_back(c); // coins larger than k are useless
    }

    // Remove duplicates and sort
    sort(coin.begin(), coin.end());
    coin.erase(unique(coin.begin(), coin.end()), coin.end());

    const int INF = 1e9;
    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    // Classic unbounded knapsack (coin change) DP
    // dp[x] = min number of coins to make sum x
    for (int c : coin) {
        for (int x = c; x <= k; ++x) {
            // If we can make (x - c), we can extend it by coin c
            dp[x] = min(dp[x], dp[x - c] + 1);
        }
    }

    cout << (dp[k] >= INF ? -1 : dp[k]) << '\n';
    return 0;
}
