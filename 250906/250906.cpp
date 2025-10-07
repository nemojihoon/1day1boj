//5557 dp
#include <iostream>

using namespace std;

int n, target;
int num[102];
long long cas[102][25];

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> num[i];
    }
    cin >> target;

    cas[0][num[0]] = 1;
    for(int i = 1; i < n-1; i++) {
        for(int j = 0; j < 21; j++) {
            if(cas[i-1][j]) {
                if(j - num[i] >= 0) {
                    cas[i][j - num[i]] += cas[i-1][j];
                }
                if(j + num[i] <= 20) {
                    cas[i][j + num[i]] += cas[i-1][j];
                }
            }
        }
    }

    cout << cas[n-2][target];

    return 0;
}