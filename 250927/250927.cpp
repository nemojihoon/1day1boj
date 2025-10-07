//15681 tree and query
#include <iostream>
#include <vector>

using namespace std;

int n, r, q, a, b, t;
vector<vector<int>> tr;
int sub[100002], vi[100002];

int dfs(int k) {
    vi[k] = 1;
    sub[k] = 1; 
    for (auto nxt : tr[k]) {
        if (!vi[nxt]) {
            sub[k] += dfs(nxt);
        }
    }
    return sub[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r >> q;
    tr.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    dfs(r);

    while (q--) {
        cin >> t;
        cout << sub[t] << '\n';
    }

    return 0;
}
