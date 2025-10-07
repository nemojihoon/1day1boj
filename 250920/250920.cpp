// 1806 queue
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 987654321
int n, s, tmp, cs;
int res = MAX;
queue<int> q;

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        q.push(tmp);
        cs += tmp;
        while(cs >= s) {
            res = min(res, (int)q.size());
            cs -= q.front();
            q.pop();
        }
    }
    cout << (res == MAX ? 0:res);
    return 0;
}