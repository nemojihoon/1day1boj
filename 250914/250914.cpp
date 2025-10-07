//1987 bfs
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int R, C, res;
char al[22][22];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
string str;

bool isBound(int x, int y) {
    return x>0 && x<R+1 && y>0 && y<C+1;
}

void f(int r, int c) {
    res = max(res, (int)str.length());
    for(int i = 0; i < 4; i++) {
        int nr, nc;
        nr = r + dx[i];
        nc = c + dy[i];
        if(!isBound(nr, nc)) continue;
        if(str.find(al[nr][nc]) == string::npos) {
            str.push_back(al[nr][nc]);
            f(nr, nc);
            str.pop_back();
        }
    }
}

int main() {
    cin >> R >> C;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> al[i][j];
        }
    }

    str.push_back(al[1][1]);
    f(1, 1);

    cout << res;
    return 0;
}