//17070 dp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;

    int r[20][20] = {0,};
    int c[20][20] = {0,};
    int d[20][20] = {0,};
    int wall[20][20] = {0,};

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> wall[i][j];
        }
    }
    
    r[1][2] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(wall[i][j] == 1) {
                r[i][j] = 0;
                c[i][j] = 0;
                d[i][j] = 0;
                continue;
            }
            r[i][j] += r[i][j-1] + d[i][j-1];
            c[i][j] += c[i-1][j] + d[i-1][j];
            
            if(wall[i][j-1] == 0 && wall[i-1][j] == 0) {
                d[i][j] += r[i-1][j-1] + c[i-1][j-1] + d[i-1][j-1];
            }

        }
    }

    cout << r[n][n] + c[n][n] + d[n][n];
    return 0;
}