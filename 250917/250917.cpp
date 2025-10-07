//14502 brute force + bfs
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, tmp, res;
int lab[10][10], vi[10][10];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> blk;
queue<pair<int, int>> q;

bool isBound(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if(lab[i][j] == 0) {
                blk.push_back({i, j});
            }
        }
    }
    

    int aidx, bidx, cidx;

    for(aidx = 0; aidx < blk.size() - 2; aidx++) {
        for(bidx = aidx + 1; bidx < blk.size() - 1; bidx++) {
            for(cidx = bidx + 1; cidx < blk.size(); cidx++) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        vi[i][j] = lab[i][j];
                        if(lab[i][j] == 2) q.push({i, j});
                    }
                }
                vi[blk[aidx].first][blk[aidx].second] = 1;
                vi[blk[bidx].first][blk[bidx].second] = 1;
                vi[blk[cidx].first][blk[cidx].second] = 1;

                while(!q.empty()) {
                    auto coor = q.front();
                    q.pop();

                    int x = coor.first, y = coor.second;
                    for(int i = 0; i < 4; i++) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if(!isBound(nx, ny)) continue;
                        if(vi[nx][ny] == 0) {
                            vi[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }

                tmp = 0;
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        if(vi[i][j] == 0) tmp++;
                    }
                }
                res = max(res, tmp);
            }
        }
    }

    cout << res;

    return 0;
}