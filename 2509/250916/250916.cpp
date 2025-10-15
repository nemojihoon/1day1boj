//13549 dp
#include <iostream>
#include <queue>

using namespace std;

#define MAX 150005

int n, k, tmp;
int vi[MAX];
queue<int> q;

int main() {
    cin >> n >> k;
    
    q.push(n);
    vi[n] = 1;

    while(!q.empty()) {
        tmp = q.front();
        q.pop();

        // cout << tmp << endl;

        if(tmp > 0 && (vi[tmp-1] == 0 || vi[tmp-1] > vi[tmp]+1)) {
            q.push(tmp-1);
            vi[tmp - 1] = vi[tmp] + 1;
        }

        if(tmp + 1 < MAX && (vi[tmp+1] == 0 || 
            vi[tmp+1] > vi[tmp]+1)) {
            q.push(tmp+1);
            vi[tmp + 1] = vi[tmp] + 1;
        }

        if(2*tmp < MAX && (vi[2*tmp] == 0 || vi[2*tmp] > vi[tmp])) {
            q.push(2*tmp);
            vi[2*tmp] = vi[tmp];
        }

    }

    cout << vi[k] - 1;
    
    return 0;
}