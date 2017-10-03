#include <bits/stdc++.h>

using namespace std;

long P(int n){
    return ((long)n * ((long)n - 1)) / 2;
}

long sumT(unordered_map<int, set<set<int>>> colSet, int l, int r){
    long sum = 0;
    for(int color = l; color <= r; ++color){
        for(auto &col : colSet[color]){
            sum += P(col.size());
        }
    }
    return sum;
}

int main() {
    bool flag = false;
    int n;
    cin >> n;
    vector<int> edges[n-1];
    set<int> col;
    for(int a0 = 0; a0 < n-1; a0++){
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        edges[a0].push_back(a-1);
        edges[a0].push_back(b-1);
        edges[a0].push_back(c);
        col.insert(c);
    }
    
    updateGraph:
    vector<int> adjEdge[n-1];
    unordered_map<int, set<set<int>>> colSet;
    set<int> Maximal[n-1];
    
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n-1; ++j){
            if(edges[i][0] == edges[j][0] || edges[i][0] == edges[j][1] || edges[i][1] == edges[j][0] || edges[i][1] == edges[j][1]){
                adjEdge[i].push_back(j);
                adjEdge[j].push_back(i);
            }
        }
    }
    

    for(int i = 0; i < n-1; ++i){
            queue<int> q;
            bool visited[n-1];                                        // might be a bug
            memset(visited, false, sizeof visited);
            q.push(i);
            Maximal[i].insert(edges[i][0]);
            Maximal[i].insert(edges[i][1]);
            visited[i] = true;
            while(!q.empty()){
                int p = q.front();
                q.pop();
                for(int j = 0; j < adjEdge[p].size(); ++j){
                    if(!visited[adjEdge[p][j]]){
                        //visited[adjEdge[p][j]] = true;
                            if( edges[p][2] == edges[adjEdge[p][j]][2]){
                                q.push(adjEdge[p][j]);
                                visited[adjEdge[p][j]] = true;
                                Maximal[p].insert(edges[adjEdge[p][j]][0]);
                                Maximal[p].insert(edges[adjEdge[p][j]][1]);
                            }
                    }
                }
            }
            colSet[edges[i][2]].insert(Maximal[i]);
    }
    if(flag){
        flag = false;
        goto querypoint;
    }
    int q, l, r, query, index, c;
    cin >> q;
    while(q--){
        cin>>query;
        switch(query){
            case 1:
                cin>>index>>c;
                edges[index - 1][2] = c;
                flag = true;
                goto updateGraph;
                break;
            case 2:
                cin>>l>>r;
                cout<<sumT(colSet, l ,r)<<endl;
                break;
            case 3:
                cin>>index;
                cout<<P(Maximal[index-1].size())<<endl;
                break;
        }
        querypoint:
        continue;
    }
    
    return 0;
}
