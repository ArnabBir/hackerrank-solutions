#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char d;
    cin >> d;
    int x;
    int y;
    cin >> x >> y;
    unordered_map<char, pair<int, int>> dir;
    unordered_map<char, char> cmpl;
    dir['w'] = make_pair(0, -1);
    dir['e'] = make_pair(0, 1);
    dir['n'] = make_pair(-1, 0);
    dir['s'] = make_pair(1, 0);
    cmpl['e'] = 'w';
    cmpl['w'] = 'e';
    cmpl['n'] = 's';
    cmpl['s'] = 'n';
    char direction[4] = {'e', 'w', 'n', 's'};
    bool visited[n][n];
    memset(visited, false, sizeof visited);
    int vizCount = 1;
    int vizCountMatrix[n][n];
    memset(vizCountMatrix, 0, sizeof vizCountMatrix);
    visited[x][y] = true;
    vizCountMatrix[x][y] = vizCount;
    while(vizCount < n*n){
        if(x + dir[d].first >= 0 && x + dir[d].first < n && y + dir[d].second >= 0 && y + dir[d].second < n){
            if(!visited[x + dir[d].first][y + dir[d].second]){
                x += dir[d].first;
                y += dir[d].second;
                visited[x][y] = true;
                ++vizCount;
                vizCountMatrix[x][y] = vizCount;
                continue;
            }
        }
            bool moved = false;
            for(int k = 0; k < 4; ++k){
                if(direction[k] == d || direction[k] == cmpl[d])  continue;
                if(x + dir[direction[k]].first >= 0 && x + dir[direction[k]].first < n && y + dir[direction[k]].second >= 0 && y + dir[direction[k]].second < n){
                    if(!visited[x + dir[direction[k]].first][y + dir[direction[k]].second]){
                        x += dir[direction[k]].first;
                        y += dir[direction[k]].second;
                        visited[x][y] = true;
                        ++vizCount;
                        vizCountMatrix[x][y] = vizCount;
                        moved = true;
                        break;
                    }
                }
            }
            if(!moved){
                if(x + (dir[cmpl[d]]).first >= 0 && x + (dir[cmpl[d]]).first < n && y + (dir[cmpl[d]]).second >= 0 && y + (dir[cmpl[d]]).second < n){
                    if(!visited[x + dir[cmpl[d]].first][y + dir[cmpl[d]].second]){
                        x += dir[cmpl[d]].first;
                        y += dir[cmpl[d]].second;
                        visited[x][y] = true;
                        ++vizCount;
                        vizCountMatrix[x][y] = vizCount;
                        moved = true;
                    }
                }
            }
        }
    
    for(int i = 0; i < n; ++i){
         for(int j = 0; j < n; ++j){
             cout<<vizCountMatrix[i][j]<<" ";
         }
        cout<<endl;
    }
    return 0;
}
