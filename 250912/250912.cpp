//1916 spf
#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

#define INF INT_MAX

int n, m, s, f, w, cur;
int ma[1005][1005], vi[1005];
queue<int> dij;

int main() {
    cin >> n >> m;
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j <= n; j++) {
            ma[i][j] = -1;

        }
        vi[i] = INF;
    }

    for(int i = 0; i < m; i++) {
        cin >> s >> f >> w;
        if(ma[s][f] == -1) {
            ma[s][f] = w;
        } else {
            ma[s][f] = min(ma[s][f], w);
        }
    }
    cin >> s >> f;
    dij.push(s);
    
    vi[s] = 0;

    while(!dij.empty()) {
        cur = dij.front();
        dij.pop();

        for(int i = 1; i <= n; i++) {
            if(ma[cur][i] != -1 && vi[i] > vi[cur] + ma[cur][i]) {
                vi[i] = vi[cur] + ma[cur][i];
                dij.push(i);
            }
        }
    }

    cout << vi[f];

    return 0;
}