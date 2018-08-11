#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the indianJob function below.
 */

int dp[101][1000001];

bool canRob(vector<int> arr, int n, int g, int set1Sum, int totalSum) {
    
    if(n == 0) {
        if( set1Sum <= g && totalSum - set1Sum <= g)   return true;
        else return false;
    }
    
    if(dp[n][set1Sum] != -1) return dp[n][set1Sum];
    bool comb1 = canRob(arr, n-1, g, set1Sum + arr[n-1], totalSum);
    bool comb2 = canRob(arr, n-1, g, set1Sum, totalSum);
    dp[n][set1Sum] = comb1 || comb2;
    return dp[n][set1Sum];
}

string indianJob(int g, vector<int> arr) {
    
    int flag;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    memset(dp, -1, sizeof dp);
    return ((totalSum <= 2 * g) && (*max_element(arr.begin(), arr.end()) <= g) && canRob(arr, arr.size(), g, 0, totalSum))   ? "YES" : "NO" ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string ng_temp;
        getline(cin, ng_temp);

        vector<string> ng = split_string(ng_temp);

        int n = stoi(ng[0]);

        int g = stoi(ng[1]);

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int arr_itr = 0; arr_itr < n; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        string result = indianJob(g, arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
