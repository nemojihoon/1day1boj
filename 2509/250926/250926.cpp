//2493 tower(stack)
#include <iostream>
#include <stack>

using namespace std;

#define INF 1000000002

int n, t;
stack<pair<int, int>> tow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    tow.push({INF, 0});
    for (int i = 1; i <= n; i++) {
        cin >> t;
        while(tow.top().first < t) tow.pop();
        cout << tow.top().second << ' ';
        tow.push({t, i});
    }
}
