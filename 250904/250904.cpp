//15686 brute force
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, chiCnt, ans;
int ci[55][55], civi[55][55];
int chivi[20];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> home;
vector<pair<int, int>> chi;
queue<pair<int, int>> cityq;

bool isInBound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void calcChiDis() {
    for(int i = 0; i < chiCnt; i++) {
        if(chivi[i] == 1) {
            auto c = chi[i];
            civi[c.first][c.second] = 1;
            cityq.push(c);
        }
    }

    while(!cityq.empty()) {
        auto coor = cityq.front();
        cityq.pop();

        for(int i = 0; i < 4; i++) {
            int nx = coor.first + dx[i], ny = coor.second + dy[i];
            if(isInBound(nx, ny)) {
                if(civi[nx][ny] == 0 || civi[nx][ny] > civi[coor.first][coor.second] + 1) {
                    civi[nx][ny] = civi[coor.first][coor.second] + 1;
                    cityq.push({nx, ny});
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(ci[i][j] == 1) {
                res += civi[i][j] - 1;
            }
        }
    }

    if(ans == 0) {
        ans = res;
    } else {
        ans = min(ans, res);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            civi[i][j] = 0;
        }
    }

    return;
}

void f(int curIn, int curCnt) {
    if(curCnt == m) {
        calcChiDis();
        // cout << curIn << " " << curCnt << endl;
        // cout << "calc" << endl;
        return;
    }
    for(int i = curIn; i < chiCnt; i++) {
        if(chivi[i] == 0) {
            chivi[i] = 1;
            f(i+1, curCnt +1);
            chivi[i] = 0;
        }
    }
    return;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> ci[i][j];
            if(ci[i][j] == 1) {
                home.push_back({i, j});
            } else if(ci[i][j] == 2) {
                chi.push_back({i, j});
                chiCnt++;
            }
        }
    }

    f(0, 0);

    cout << ans;

    return 0;
}