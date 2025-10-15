//2565 dp
#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::sort;
using std::vector;
using std::pair;
using std::max;

int n;

int main() {
    cin >> n;
    vector<pair<int, int>> wires(n);
    for(int i = 0; i < n; i++) {
        cin >> wires[i].first >> wires[i].second;
    }

    sort(wires.begin(), wires.end());

    vector<int> dp(n,1);
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(wires[i].second > wires[j].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << n - res;
}