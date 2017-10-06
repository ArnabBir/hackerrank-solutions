#define MAXVAL (int)1e9

int minimumLength(string text, vector < string > keys) {

    int answer = MAXVAL;
    text += " ";
    int dp[text.length()] = {-1};
    vector<pair<int, int>> loc;
    string word = "";
    for(int j = 0; j < text.size(); j++) {
            if(text[j] == ' ') {
                for(int k = 0; k < keys.size(); k++) {
                    if(keys[k] == word) {
                        dp[j-keys[k].length()] = k;
                        loc.push_back(make_pair(j-keys[k].length(), (int)keys[k].length()));
                        //dup.erase(dup.begin() + k);
                        break;
                    }
                }
                word = "";
            }
            else word += text[j];
    }
    
    for(int j = 0; j < loc.size(); ++j){
        bool visited[keys.size()] = {false};
        int count = 0;
        string lastWord;
        for(int i = j; i < loc.size(); ++i){
            if(!visited[dp[loc[i].first]]){
                visited[dp[loc[i].first]] = true;
                ++count;
                lastWord = keys[dp[loc[i].first]];
            }
            if(count == keys.size()){
                answer = min(loc[i].first - loc[j].first +  loc[i].second, answer);
                break;
            }
        }
    }
    
    if(answer == MAXVAL)
        answer = -1;

    return answer;
}

