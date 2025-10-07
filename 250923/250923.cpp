//11000 greedy + priority queue
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> meet;
priority_queue<int, vector<int>, greater<int>> finTime;

int main() {
    cin >> n;
    meet.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> meet[i].first >> meet[i].second;
    }

    sort(meet.begin(), meet.end());
    finTime.push(0);

    for(int i = 0; i < n; i++) {
        int j = 0;
        int mi = finTime.top();
        if(mi <= meet[i].first) {
            finTime.pop();
        }
        finTime.push(meet[i].second);
    }

    cout << finTime.size();

    return 0;
}