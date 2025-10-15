//1520 dp
#include <iostream>

using namespace std;

int m, n;
int moun[505][505], vi[505][505];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int f(int x, int y) {
    if(vi[x][y] != -1)    return vi[x][y];
    if(x == m && y == n)    return 1;

    vi[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(moun[nx][ny] != 0 && moun[nx][ny] < moun[x][y]) {
            vi[x][y] += f(nx, ny);
        }
    }
    return vi[x][y];
}

int main() {
    cin >> m >> n;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> moun[i][j];
            vi[i][j] = -1;
        }
    }
    
    cout << f(1, 1);
    return 0;
}