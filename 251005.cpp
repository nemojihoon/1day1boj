//4948 Bertrand's postulate
#include <iostream>

using namespace std;

int n;
int era[500000];

int main() {
    while(true) {
        cin >> n;
        if(n == 0) return 0;
        for(int i = 2; i <= 2*n; i++) {
            if(era[i] == 0) {
                for(int j = 2; i*j <= 2*n; j++) {
                    era[i*j] = 1;
                }
            }
        }

        int cnt = 0;
        for(int i = n+1; i <= 2*n; i++) {
            if(era[i] == 0) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}