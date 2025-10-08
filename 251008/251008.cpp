//11725 dfs
#include <iostream>
#include <vector>

using namespace std;

int n, a, b;
int pa[100002];
vector<vector<int>> tr;

void dfs(int k) {
    for(int nxt:tr[k]) {
        if(pa[nxt] == 0) {
            pa[nxt] = k;
            dfs(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);            
    cout.tie(nullptr); 

    cin >> n;
    tr.resize(n+1);
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    pa[1] = 1;
    dfs(1);
    for(int i = 2; i <= n; i++) {
        cout << pa[i] << '\n';
    }
    return 0;
}