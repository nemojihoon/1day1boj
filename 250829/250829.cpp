//2225 dp
#include <iostream>

using std::cin;
using std::cout;

#define MOD 1000000000
int n, k;
int dp[202][202];

int main() {
    cin >> n >> k;
    for(int j = 0; j <= n; j++) {
        dp[1][j] = 1;
    }
    for(int i = 2; i <=k; i++) {
        for(int j = 0; j <=n; j++) {
            if(j == 0) {
                dp[i][j] = 1;
                continue;
            } else {
                for(int l = 0; l <= j; l++) {
                    dp[i][j] += dp[i-1][l];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[k][n];
    return 0;
}