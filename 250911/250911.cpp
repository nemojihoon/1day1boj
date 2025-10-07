//9252 LCS backtracking
#include <iostream>
#include <string>

using namespace std;

int len;
string s1, s2, res;
int dp[1002][1002];

int main() {
    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++) {
        for(int j = 0; j < s2.length(); j++) {
            if(s1[i] != s2[j]) {
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            } else {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
        }
    }

    int i = s1.length(), j = s2.length();
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            res = s1[i-1] + res;
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    len = dp[s1.length()][s2.length()];
    cout << len;
    if(len) {
        cout << endl << res;
    }
    return 0;
}