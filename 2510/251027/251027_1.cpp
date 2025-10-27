//1931 interval partitioning
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a, b;
vector<pair<int, int>> meet;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        meet.push_back({a, b});
    }
    sort(meet.begin(), meet.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int t = 0, cnt = 0;
    for(auto m:meet) {
        if(m.first >= t) {
            t = m.second;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}