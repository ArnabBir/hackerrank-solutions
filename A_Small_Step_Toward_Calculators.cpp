#include <bits/stdc++.h>

using namespace std;

int solve(string opr) {
    if(opr[1] == '+')   return (int)opr[0] + (int)opr[2] - 2 * (int)'0';
    else    return (int)opr[0] - (int)opr[2];
}

int main() {
    string opr;
    cin >> opr;
    int result = solve(opr);
    cout << result << endl;
    return 0;
}
