//14675 using tree's characteristics
#include <iostream>
using namespace std;

int n, q, a, b, deg[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        if(a == 1) {
            cout << (deg[b] > 1 ? "yes\n":"no\n");
        } else {
            cout << "yes\n";
        }
    }

    return 0;
}