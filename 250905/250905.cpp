//13398 dp
#include <iostream>
#include <algorithm>

using namespace std;

#define MIN -1e8
int n, res = MIN;
int num[100002], dp[100002][3];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        dp[i][0] = max(dp[i-1][0]+ num[i], num[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + num[i]);
        dp[1][1] = MIN;
        res = max(res, max(dp[i][0], dp[i][1]));

        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    
    cout << res;
    return 0;
}