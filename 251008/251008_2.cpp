//9657 dp
#include <iostream>

using namespace std;

int n , game[1002] = {0, 1, -1, 1, 1, 1,};

int main() {
    cin >> n;
    for(int i = 5; i <= n; i++) {
        if(game[i-1] + game[i-3] + game[i-4] == 3) {
            game[i] = -1;
        } else {
            game[i] = 1;
        }
    }
    cout << (game[n] == 1 ? "SK":"CY");
    return 0;
}