#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */

int findParent(vector<int> & parent, int n) {

    if(parent[n] == -1) return n;
    return findParent(parent, parent[n]);
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    
    vector<int> parent(2*gb.size()+1, -1);
    vector<int> setSize(2*gb.size()+1, 1);
    for(int i = 0; i < gb.size(); ++i) {
        int x = findParent(parent, gb[i][0]);
        int y = findParent(parent, gb[i][1]);
        if(x != y) {
            parent[y] = x;
            setSize[x] += setSize[y];
            setSize[y] = 0;
        }
    }

    vector<int> result(2);
    result[0] = INT_MAX;
    result[1] = 0;
    for(auto & i : setSize) {
        if(result[1] < i) {
            result[1] = i;
        }
        if(result[0] > i && i > 1) {
            result[0] = i;
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> SPACE = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < SPACE.size(); SPACE_itr++) {
        fout << SPACE[SPACE_itr];

        if (SPACE_itr != SPACE.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
