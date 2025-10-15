//11404 Floyd-Warshall
#include <iostream>

using namespace std;

#define INF 1e8

int n, m, a, b, w;
int gra[102][102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            gra[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        gra[a][b] = min(gra[a][b], w);
    }

    for(int k= 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                gra[i][j] = min(gra[i][j], gra[i][k] + gra[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(gra[i][j] == INF) cout << 0 << ' ';
            else cout << gra[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}