//10942 palindrom dp
#include <iostream>
using namespace std;

int n, m, s, e;
int num[2002];
int dp[2002][2002];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);      

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    // DP 전처리
    for (int len = 1; len <= n; len++) {
        for (int start = 1; start <= n - len + 1; start++) {
            int end = start + len - 1;
            if (len == 1) {
                dp[start][end] = 1;
            } else if (len == 2) {
                dp[start][end] = (num[start] == num[end]) ? 1 : 0;
            } else {
                dp[start][end] = (num[start] == num[end] && dp[start + 1][end - 1]);
            }
        }
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }

    return 0;
}
