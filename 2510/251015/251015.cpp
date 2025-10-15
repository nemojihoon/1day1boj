//1707 Bipartite Graphs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tc, n, m, a, b;
vector<vector<int>> gra;
vector<int> vis;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> tc;
    for(int t = 0; t < tc; t++) {
        cin >> n >> m;
        gra.resize(n+1);
        vis.resize(n+1);
        for(int i = 0; i < m; i++) {
            cin >> a >> b;
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        queue<int> qu;
        for(int start = 1; start <= n; start++) {
            if(vis[start] == 0) {
                qu.push(start);
                vis[start] = 1;
                int cur;
                while(!qu.empty()) {
                    cur = qu.front();
                    qu.pop();
                    for(auto nxt:gra[cur]) {
                        if(vis[nxt] != 0) continue;
                        qu.push(nxt);
                        vis[nxt] = -vis[cur];
                    }
                }
            }
        }
        
        bool flag = true;
        for(int i = 1; i <= n; i++) {
            for(int j:gra[i]) {
                if(vis[i] == vis[j]) {
                    flag = false;
                }
            }
        }
        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        gra.clear();
        vis.clear();
    }
    return 0;
}