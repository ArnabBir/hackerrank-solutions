#include <bits/stdc++.h>

using namespace std;

vector<string> board(8);
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int cont;
char s[12];
string secret;
int countSecret = 0;
bool visited[8][8];

void show(int x,int y) {
  s[cont] = board[x][y];
  if(s[cont] != secret[cont] || visited[x][y])   return;
  if(cont == secret.length() - 1) {
    memset(visited, false, sizeof visited);
    ++countSecret;
    return;
  }
  visited[x][y] = true;
  int xx,yy;
  for(int i = 0; i < 8; ++i) {
    xx = x + dx[i], yy = y + dy[i];
    if(0 <= xx and xx < 8 and 0 <= yy and yy < 8) {
        ++cont;
        show(xx, yy);
        --cont;
    }
  }
}

int main() {
    int k;
    cont = 0;
    cin >> k;
    cin >> secret;
    for(int board_i = 0; board_i < 8; board_i++){
       cin >> board[board_i];
    }
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(board[i][j] == secret[0]){      
                memset(visited, false, sizeof visited);
                show(i, j);
            }
        }
    }
    cout<<countSecret<<endl;
    return 0;
}
