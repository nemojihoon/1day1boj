//2056 graph + dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, t, preCnt, pre, cur, nxt, res;
vector<vector<int>> gra(10002);
int task[10002][2], dp[10002];
queue<int> q;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> task[i][0] >> task[i][1];
        for(int j = 0; j < task[i][1]; j++) {
            cin >> pre;
            gra[pre].push_back(i);
        }
        if(task[i][1] == 0) {
            q.push(i);
            dp[i] = task[i][0];
        }
    }

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        res = max(res, dp[cur]);

        for(int i = 0; i < gra[cur].size(); i++) {
            nxt = gra[cur][i];
            dp[nxt] = max(dp[nxt], dp[cur] + task[nxt][0]);

            task[nxt][1]--;
            if(task[nxt][1] == 0) q.push(nxt);
        }
    }

    cout << res;
    return 0;
}