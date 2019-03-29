#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {

    int flag, count;
    int maxLen = 0;
    unordered_map<char, vector<int>> um;
    set<char> characters;
    vector<char> vecChars; 
    for(int i = 0; i < s.length(); ++i) {
        characters.insert(s[i]);
        um[s[i]].push_back(i);
    }
    for(auto & c : characters) {
        vecChars.push_back(c);
    }
    for(int i = 0; i < vecChars.size(); ++i) {
        for(int j = i+1; j < vecChars.size(); ++j) {
            flag = 0;
            count = 0;
            vector<int> iIndex = um[vecChars[i]];
            vector<int> jIndex = um[vecChars[j]];
            if(abs((int)iIndex.size() - (int)jIndex.size()) > 1) {
                continue;
            }
            int k = 0, l = 0;
            while(k < iIndex.size() && l < jIndex.size()) {
                if(iIndex[k] < jIndex[l]) {
                    if(flag == 0) {
                        if(k < iIndex.size()-1) {
                            if(iIndex[k+1] < jIndex[l]) {
                                flag = 3;
                                break;
                            }
                        }
                        ++k;
                        ++l;
                        flag = 1;
                    }
                    else if(flag == 1) {
                        if(k < iIndex.size()-1) {
                            if(iIndex[k+1] < jIndex[l]) {
                                flag = 3;
                                break;
                            }
                        }
                        ++k;
                        ++l;
                    }
                    else if(flag == 2) {
                        flag = 3;
                        break;       
                    }
                }
                else {
                    if(flag == 0) {
                        if(l < jIndex.size()-1) {
                            if(jIndex[l+1] < iIndex[k]) {
                                flag = 3;
                                break;
                            }
                        }
                        ++k;
                        ++l;
                        flag = 2;
                    }
                    else if(flag == 2) {
                        if(l < jIndex.size()-1) {
                            if(jIndex[l+1] < iIndex[k]) {
                                flag = 3;
                                break;
                            }
                        }
                        ++k;
                        ++l;
                    }
                    else if(flag == 1) {
                        flag = 3;
                        break;       
                    }
                } 
            }
            if( k+1 == iIndex.size()) {
                if(flag == 2) {
                    continue;
                }
            }
            else if( l+1 == jIndex.size()) {
                if(flag == 1) {
                    continue;
                }
            }
            if(flag != 3) {                
                maxLen = max(maxLen, (int)iIndex.size() + (int)jIndex.size());
            }
        }
    }
    return maxLen;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
