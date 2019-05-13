#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    string temp = "", result = "";
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] != ' ') temp += s[i];
    }
    int L = temp.length();
    double rootL = sqrt(L);
    int rows = floor(rootL), cols = ceil(rootL);
    if(rows * cols < L) ++rows;
    int l = 0;
    string mat[cols];
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(l >= L) {
                break;
            }
            mat[j] += temp[l++];
        }
    }
    for(int i = 0; i < cols; ++i)   result += mat[i] + ' ';
    result += '\n';
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
