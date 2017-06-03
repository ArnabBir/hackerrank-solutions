#include <vector>
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;


bool findPassword(vector<string> password, string input, vector<string> &result){
    bool found = false;
    if(input.length() == 0){
        return true;
    }
    for(int i = 0; i <= input.length(); ++i){
        if(find(password.begin(), password.end(), input.substr(0, i)) != password.end()){
            result.push_back(input.substr(0, i));
            input.erase(0,i);
            found = true;
            found = findPassword(password, input, result);
            break;
        }
        else    found = false;
    }
    return found;
}

int main() {
    int T, N;
    string pw, input;
    cin>>T;
    while(T--){
        cin>>N;
        vector<string> password, result;
        for(int i = 0; i < N; ++i){
            cin>>pw;
            password.push_back(pw);
        }
        cin>>input;
        if(findPassword(password, input, result)){
            for(vector<string>::iterator it = result.begin(); it != result.end(); ++it){
                cout<<*it<<" ";
            }
        }
        else    cout<<"WRONG PASSWORD";
        cout<<endl;
    }
    return 0;
}
