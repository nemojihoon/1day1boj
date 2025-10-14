//1948 Prim
#include <iostream>
#include <vector>

using namespace std;

#define INF 1e11

int n, m, a, b, visited[10002];
long long dist[10002], res, w;
vector<vector<pair<int, int>>> gra;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    gra.resize(n+1);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        gra[a].push_back({b, w});
        gra[b].push_back({a, w});
    }

    for(int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    int cur = 1;
    dist[1] = 0;

    for(int i = 1; i <= n; i++) {
        long long minDis = INF;
        int minId = 0;
        for(int j = 1; j <= n; j++) {
            if(visited[j] == 0 && minDis > dist[j]) {
                minDis = dist[j];
                minId = j;
            }
        }
        cur = minId;
        res += minDis;
        visited[cur] = 1;

        for(auto nxt:gra[cur]) {
            if(visited[nxt.first] == 0 && nxt.second < dist[nxt.first]) {
                dist[nxt.first] = nxt.second;
            }
        }
    }

    cout << res;

    return 0;
}