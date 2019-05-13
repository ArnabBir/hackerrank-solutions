#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */

 string getString(char x) { 
    string s(1, x); 
    return s;    
} 
string timeConversion(string s) {
    int hr = stoi(s.substr(0,2));
    if(s[s.length()-2] == 'A') {
        if(hr == 12) {
            return "00" + s.substr(2, 6);
        }
        else    return s.substr(0, 8);
    }
    else {
        if(hr == 12){
            return s.substr(0, 8);
        }
        else    return to_string(hr + 12) + s.substr(2, 6);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
