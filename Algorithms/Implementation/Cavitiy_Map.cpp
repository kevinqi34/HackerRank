#include <bits/stdc++.h>


using namespace std;

int convert(char in) {
    return in - '0';
}



int main(){
    // Save Cavities
    vector<pair<int, int>> cavities;
    // Load Grid
    int n;
    cin >> n;
    vector<vector <char>> grid;
    for (int i = 0; i < n; i++) {
        vector<char> tmp;
        for (int j = 0; j < n; j++) {
            char in;
            cin >> in;
            tmp.push_back(in);
        }
        grid.push_back(tmp);
    }

    // Track Postions in the center of Grid
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            // Find cavities
            char current = grid[i][j];
            if (convert(current) > convert(grid[i-1][j]) && convert(current) > convert(grid[i+1][j])
                && convert(current) > convert(grid[i][j+1]) && convert(current) > convert(grid[i][j-1])
               )
            {
                pair<int, int> tmp;
                tmp.first = i;
                tmp.second = j;
                cavities.push_back(tmp);

            }


        }
    }

    // Mark
    for (auto i : cavities) {
        grid[i.first][i.second] = 'X';

    }



    // Output
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           cout << grid[i][j];
        }
        cout << endl;
    }


    return 0;
}
