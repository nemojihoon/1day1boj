//9251 LCS
#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int dp[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] == s2[j]) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                if(i == 0 && j == 0) continue;
                if(i == 0) dp[i][j] = dp[i][j-1];
                else if(j == 0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.length()-1][s2.length()-1];

    return 0;
}