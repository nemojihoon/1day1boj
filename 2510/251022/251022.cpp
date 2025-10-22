//7577 difference constraint(bellman ford)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 1e5

int k, n, a, b, r, gift[45], start = 1;
int gra[45][45], dist[45];
struct Edge {
    int s, e, w;
};
vector<Edge> edges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> n;
    for(int i = 1; i <= k+1; i++) {
        for(int j = 1; j <= k+1; j++) {
            if(j >= i) gra[i][j] = j-i;
            else gra[i][j] = 0;
        }
        dist[i] = INF;
    }
    dist[1] = 0;

    for(int i = 0; i < n; i++) {
        cin >> a >> b >> r;
        for(int j = 1; j <= a; j++) {
            gra[b+1][j] = min(gra[b+1][j], -r);
        }
        gra[a][b+1] = min(gra[a][b+1], r);
        for(int j = b+1; j <= k+1; j++) {
            gra[j][a] = min(gra[j][a], -r);
        }
    }

    // for(int i = 1; i <= k+1; i++) {
    //     for(int j = 1; j <= k+1; j++) {
    //         cout << gra[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int l = 0; l < k; l++) {
        for(int i = 1; i <= k+1; i++) {
            for(int j = 1; j <= k+1; j++) {
                if(gra[i][j] != INF) {
                    dist[j] = min(dist[j], dist[i] + gra[i][j]);
                }
            }
        }
    }

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            if(gra[i][j] != INF && (dist[j] > dist[i] + gra[i][j])) {
                cout << "NONE";
                return 0;
            }
        }
    }

    // for(int i = 0; i <= k+1; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;

    for(int i = 2; i <= k+1; i++) {
        if(dist[i] > dist[i-1]) cout << '#';
        else cout << '-';
    }
    return 0;
}