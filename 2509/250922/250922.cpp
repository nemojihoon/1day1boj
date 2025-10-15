//19598 interval partitioning
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> meet;
vector<int> finTime;

int main() {
    cin >> n;
    meet.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> meet[i].first >> meet[i].second;
    }

    sort(meet.begin(), meet.end());
    finTime.push_back(0);

    for(int i = 0; i < n; i++) {
        int j = 0;
        for(j = 0; j < finTime.size(); j++) {
            if(finTime[j] <= meet[i].first) {
                finTime[j] = meet[i].second;
                break;
            }
        }
        if(j == finTime.size()) {
            finTime.push_back(meet[i].second);
        }
    }

    cout << finTime.size();

    return 0;
}