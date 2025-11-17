//14621 Kruskal
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, e, w, cnt, res;
char c;
struct Edge {
    int u, v, w;
};
vector<int> gender, par;
vector<Edge> edges;

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int find(int k) {
    if(par[k] == k) return k;
    return par[k] = find(par[k]);
}

void uni(int a, int b) {
    par[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    gender.resize(n+1);
    par.resize(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> c;
        gender[i] = (c == 'M' ? 1 : 0);
        par[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> w;
        if(gender[s] == gender[e]) continue;
        edges.push_back({s, e, w});
    }
    sort(edges.begin(), edges.end(), cmp);
    for(auto edge:edges) {
        if(find(edge.u) != find(edge.v)) {
            cnt++;
            res += edge.w;
            uni(edge.u, edge.v);
        }
    }
    cout << (cnt == n-1 ? res : -1);
    return 0;
}