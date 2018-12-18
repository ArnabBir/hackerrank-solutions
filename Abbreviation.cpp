#include <bits/stdc++.h>

using namespace std;



// Complete the abbreviation function below.
bool abbreviation(string a, string b) {

  vector<vector<bool>> dp(a.size()+1, vector<bool> (b.size()+1));

  for (int i = 0; i <= b.size(); ++i) {
    for (int j = 0; j <= a.size(); ++j) {
      if (i == 0 && j == 0) {
        dp[j][i] = true;
      } else if (i == 0 && j != 0) {
        dp[j][i] = (a[j - 1] >= 'a') && dp[j - 1][i];
      } else if (i != 0 && j != 0) {
        if (a[j - 1] == b[i - 1]) {
          dp[j][i] = dp[j - 1][i - 1];
        } else if (a[j - 1] - 32 == b[i - 1]) {
          dp[j][i] = dp[j - 1][i - 1] || dp[j - 1][i];
        } else if (a[j - 1] >= 'a') {
          dp[j][i] = dp[j - 1][i];
        }
      }
    }
    }
    return dp[a.size()][b.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        //memset(dp, 0, sizeof dp);
        bool result = abbreviation(a, b);
        fout << (result ? "YES" : "NO") << "\n";
    }

    fout.close();

    return 0;
}
