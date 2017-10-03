#include <iostream>
#include <stdio.h>
#include <set>

const int N = 1e3 + 10;

using namespace std;

char board[N][N];
int mexArray[N][N];

int n;

int mexInCell(int x, int y) {
    if (x <= 0 || x > n) return -1;
    if (y <= 0 || y > n) return -1;
    if (board[x][y] == 'X') return -1;
    return mexArray[x][y];
}

int getMex(int x, int y) {
    set <int> st;
    st.insert(mexInCell(x - 1, y));
    st.insert(mexInCell(x, y - 1));
    st.insert(mexInCell(x - 1, y - 1));
    for (int i = 0;; i++) {
        if (st.find(i) == st.end())
            return i;
    }
}

int isGood(int x, int y, int xorSum) {
    if (x <= 0 || x > n) return 0;
    if (y <= 0 || y > n) return 0;
    if (board[x][y] == 'X') return 0;
    return (xorSum == mexArray[x][y]);
}

void fillMexArray() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mexArray[i][j] = getMex(i, j);
        }
    }
}

int main() {
    int q;
    scanf ("%d", &q);

    while (q--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%s\n", board[i]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                board[i][j] = board[i][j - 1];
                mexArray[i][j] = 0;
            }
        }

        fillMexArray();

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << mexArray[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int mexXor = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i][j] == 'K')
                    mexXor ^= mexArray[i][j];
            }
        }

        if (mexXor == 0) {
            puts("LOSE");
        } else {
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (board[i][j] == 'K') {
                        ans += isGood(i - 1, j, mexXor ^ mexArray[i][j]);
                        ans += isGood(i, j - 1, mexXor ^ mexArray[i][j]);
                        ans += isGood(i - 1, j - 1, mexXor ^ mexArray[i][j]);
                    }
                }
            }
            printf("WIN %d\n", ans);
        }

    }
}Bob's Game
