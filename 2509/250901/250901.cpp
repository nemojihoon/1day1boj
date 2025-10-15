//1931 interval scheduling

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::sort;

int n;


int main() {
    cin >> n;
    vector<pair<int, int>> meet(n);
    for(int i = 0; i < n; i++) {
        cin >> meet[i].first >> meet[i].second;
    }
    sort(meet.begin(), meet.end(), [](auto &left, auto &right) {
        if(left.second == right.second) return left.first < right.first;
        return left.second < right.second;
    });

    int tmp = 0, cnt =  0;

    for(int i = 0; i < n; i++) {
        if(meet[i].first >= tmp) {
            cnt++;
            tmp = meet[i].second;
        }
    }

    cout << cnt;
    return 0;
}