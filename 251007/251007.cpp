//1753 dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define INF 3000005

int v, e, s, a, b, w;
vector<unordered_map<int, int>> gra;
int dis[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin >> v >> e;
    cin >> s;
    gra.resize(v+1);

    for(int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        if(gra[a].count(b)) {
            gra[a][b] = min(gra[a][b], w);
        } else {
            gra[a][b] = w;
        }
    }

    for(int i = 1; i <= v; i++) {
        dis[i] = INF;
    }

    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        int cur_dis = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(auto nxt:gra[cur]) {
            if(dis[nxt.first] > cur_dis + nxt.second) {
                dis[nxt.first] = cur_dis + nxt.second;
                pq.push({dis[nxt.first], nxt.first});
            }
        }
    }

    for(int i = 1; i <= v; i++) {
        if(dis[i] == INF) cout << "INF" << "\n";
        else cout << dis[i] << "\n";
    }

    return 0;
}