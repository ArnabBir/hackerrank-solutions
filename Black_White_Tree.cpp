#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+20;
int F[Maxn][2];
int c[Maxn];
vector<int> d[Maxn];
int ans = 0;
int ansRoot = 0;
int ansP = 0;
int ansC = -1;
vector<int> ansNodes;
void dfs(int node,int pr){
    int T[2] = {0,0};
    for(int u:d[node])if(u!=pr){
        dfs(u,node);
        T[0] += F[u][0];
        T[1] += F[u][1];
    }
    F[node][c[node]] = max(1, T[c[node]] + 1);
    F[node][!c[node]] = max(0, T[!c[node]] - 1);
    if(F[node][0] > ans){
        ans = F[node][0];
        ansRoot = node;
        ansC = 0;
        ansP = pr;
    }
    if(F[node][1] > ans){
        ans = F[node][1];
        ansRoot = node;
        ansC = 1;
        ansP = pr;

    }

}
void trace(int node,int pr){
    ansNodes.push_back(node);
    for(int u: d[node]) if(u!= pr && F[u][ansC] > 0){
        trace(u,node);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    dfs(1,0);
    cout << ans <<'\n';
    trace(ansRoot, ansP);
    cout << ansNodes.size();
    for(int i = 0; i < ansNodes.size(); i++)
        cout << (i?' ':'\n') <<ansNodes[i];
    return 0;
}
