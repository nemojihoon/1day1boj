//1043 graph
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, tCnt, tp, pCnt, a, b;
int par[55][55], visit[55];
bool sumFlag = false;
int res;
vector<vector<int>> partyList;
queue<int> partyq;

int main() {
    cin >> n >> m;
    cin >> tCnt;

    partyList.resize(m);

    for(int i = 0; i < tCnt; i++) {
        cin >> tp;
        visit[tp] = 1;
        partyq.push(tp);
    }

    for(int i = 0; i < m; i++) {
        cin >> pCnt;
        cin >> a;
        partyList[i].push_back(a);
        for(int j = 1; j < pCnt; j++) {
            cin >> b;
            partyList[i].push_back(b);
            par[a][b] = 1;
            par[b][a] = 1;
            a = b;
        }
    }

    while(!partyq.empty()) {
        int tmp = partyq.front();
        partyq.pop();
        // cout << "tmp: " << tmp << endl;

        for(int i = 1; i <= n; i++) {
            if(par[tmp][i] == 1 && visit[i] == 0) {
                partyq.push(i);
                visit[i] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        if(visit[partyList[i].front()] == 0) {
            res++;
        }
    }

    cout << res;

    return 0;

}