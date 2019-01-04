#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the downToZero function below.
 */

vector<int> dp(1000001, -1);
int n = 1000001;

void downToZero() {

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 0; i <= n; ++i) {
        if(dp[i] == -1 || dp[i] > (dp[i-1] + 1)) {
            dp[i] = dp[i-1] + 1;
        }
        for(int j = 2; j <= i && i*j <= n; ++j) {
            if(dp[i*j] == -1 || dp[i*j] > dp[i] + 1) {
                dp[i*j] = dp[i] + 1;
            }
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    downToZero();

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        fout << dp[n] << "\n";
    }

    fout.close();

    return 0;
}
