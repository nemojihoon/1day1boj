//11400 articulation bridges
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, q, a, b, root, cnt;
int dt[100002], low[100002], par[100002];
vector<pair<int, int>> edges, arte;
vector<vector<int>> tree;

void dfs(int k) {
    dt[k] = ++cnt;
    low[k] = dt[k];
    for(auto nxt:tree[k]) {
        if(nxt == par[k]) continue;
        if(dt[nxt] == 0) {
            par[nxt] = k;
            dfs(nxt);
            low[k] = min(low[k], low[nxt]);
            if(low[nxt] > dt[k]) {
                if(k < nxt) arte.push_back({k, nxt});
                else arte.push_back({nxt, k});
            }
        } else {
            low[k] = min(low[k], dt[nxt]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    tree.resize(n+1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    root = 1;
    par[root] = root;
    dfs(root);

    sort(arte.begin(), arte.end());
    cout << arte.size() << '\n';
    for(auto e:arte) {
        cout << e.first << ' ' << e.second << '\n';
    }

    return 0;
}