//11657 Bellman-Ford
#include <iostream>

using namespace std;

#define INF 987654321

int v, e, s, a, b, w;
long long edges[300002][3], vi[20002];

int main() {
    cin >> v >> e;
    s = 1;
    for(int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    for(int i = 1; i <= v; i++) {
        vi[i] = INF;
    }

    vi[s] = 0;


    for(int i = 0; i < v-1; i++) {
        for(int j = 0; j < e; j++) {
            a = edges[j][0];
            b = edges[j][1];
            w = edges[j][2];
            if(vi[a] != INF && vi[b] > vi[a] + w) {
                vi[b] = vi[a] + w;
            }
        }
    }

    for(int j = 0; j < e; j++) {
            a = edges[j][0];
            b = edges[j][1];
            w = edges[j][2];
            if(vi[a] != INF && vi[b] > vi[a] + w) {
                cout << -1;
                return 0;
            }
        } 

    for(int i = 2; i <= v; i++) {
        if(vi[i] == INF) cout << -1 << "\n";
        else cout << vi[i] << "\n";
    }
}