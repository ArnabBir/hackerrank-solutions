#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> volcano[m];
    int score[n][n];
    memset(score, 0, sizeof score);
    int maxScore = 0;
    for(int a0 = 0; a0 < m; a0++){
        int x;
        int y;
        int w;
        cin >> x >> y >> w;
        volcano[a0].push_back(x);
        volcano[a0].push_back(y);
        volcano[a0].push_back(w);
        if(maxScore < w)    maxScore = w;
        score[x][y] += w;
    }
    for(int i = 0; i < m; ++i){
        int power = volcano[i][2];
        while(power-- > 1){
            for(int l = -power; l <= power; ++l){
                if(volcano[i][1] + l >= 0 && volcano[i][1] + l < n && volcano[i][0] - power >= 0 && volcano[i][0] - power < n){
                    score[volcano[i][0] - power][volcano[i][1] + l] += volcano[i][2] - power;
                    maxScore = max(score[volcano[i][0] - power][volcano[i][1] + l], maxScore);
                }
                if(volcano[i][1] + l >= 0 && volcano[i][1] + l < n && volcano[i][0] + power >= 0 && volcano[i][0] + power < n){
                    score[volcano[i][0] + power][volcano[i][1] + l] += volcano[i][2] - power;
                    maxScore = max(score[volcano[i][0] + power][volcano[i][1] + l], maxScore);
                }
            }
            for(int k = -power+1; k <= power-1; ++k){
                if(volcano[i][0] + k >= 0 && volcano[i][0] + k < n && volcano[i][1] - power >= 0 && volcano[i][1] - power < n){
                    score[volcano[i][0] + k][volcano[i][1] - power] += volcano[i][2] - power;
                    maxScore = max(score[volcano[i][0] + k][volcano[i][1] - power], maxScore);
                }
                if(volcano[i][0] + k >= 0 && volcano[i][0] + k < n && volcano[i][1] + power >= 0 && volcano[i][1] + power < n){
                    score[volcano[i][0] + k][volcano[i][1] + power] += volcano[i][2] - power;
                    maxScore = max(score[volcano[i][0] + k][volcano[i][1] + power], maxScore);
                }
            }
        }
    }
    cout<<maxScore<<endl;

    return 0;
}
