//15486 dp
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::max;

int n;
int t[1500005][2];
int dp[1500005];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i][0] >> t[i][1];
    }

    for(int i = n; i>0; i--) {
        if(i + t[i][0] <= n + 1) {
            dp[i] = max(dp[i+t[i][0]] + t[i][1], dp[i+1]);
        } else {
            dp[i] = dp[i+1];
        }
    }

    cout << dp[1];


    return 0;
}