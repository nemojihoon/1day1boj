//1647 Kruskal2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int s, e, w;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

int n, m, pa[100002], a, b, w, res, cnt;
vector<Edge> edges;

int find(int cur) {
    if(pa[cur] == cur) return cur;
    return pa[cur] = find(pa[cur]);
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        pa[i] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        Edge newE = {a, b, w};
        edges.push_back(newE);
    }

    sort(edges.begin(), edges.end(), cmp);

    for(auto edge:edges) {
        if(cnt >= n-2) break;
        int a = edge.s;
        int b = edge.e;
        int w = edge.w;
        int ap = find(a);
        int bp = find(b);
        if(ap == bp) continue;
        if(ap < bp) {
            pa[bp] = ap;
        } else {
            pa[ap] = bp;
        }
        res += w;
        cnt++;
    }

    cout << res;
    return 0;
}