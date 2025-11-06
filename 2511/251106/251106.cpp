//12865 knapsack
#include <iostream>
using namespace std;

int n, k, bag[102][3], dp[100002], res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> bag[i][0] >> bag[i][1];
        for(int j = k; j >= bag[i][0]; j--) {
            dp[j] = max(dp[j], dp[j-bag[i][0]] + bag[i][1]);
        }
    }
    cout << dp[k];

    return 0;
}