//1967 the diameter of tree
//with solution
// diameter >= max distance from root
// finde max dis node from root and repeat same process from maxnode

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int>V;
vector<pair<int,int> >node[10001];
int maxVal=-1, maxnode=0;
void dfs(int now, int val);
int main(){
    cin>>n;
    V.resize(n+1,0);
    int s,e,w;
    for(int i=0; i<n-1; i++){
        cin>>s>>e>>w;
        node[s].push_back(make_pair(e,w));
        node[e].push_back(make_pair(s,w));
    }
    dfs(1,0);
    V.assign(n+1,0);
    maxVal=-1;
    dfs(maxnode,0);
    cout<<maxVal<<endl;
}
void dfs(int now, int val){

    V[now]=1;
    if(maxVal < val){ 
        maxVal=val;
        maxnode=now;
    }
    for(int i=0; i<node[now].size();i++){ 
        if(V[node[now][i].first]==1) 
            continue;
        dfs(node[now][i].first,val+node[now][i].second);
    }
}