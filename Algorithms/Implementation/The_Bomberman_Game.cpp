#include <bits/stdc++.h>

using namespace std;

void print_grid(vector< vector<int>> input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] > 0) {
                cout << "O";
            } else {
                cout << ".";
            }
        } // For
        cout << endl;
    }
    cout << endl;
}

// Advance state forward by 1
vector< vector<int>> advanceState(vector <vector<int>> input, int height, int width) {
    vector <vector<int>> output = input;
    // Iterate
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            if (input[i][j] == 1) {
                // Explode
                output[i][j] = 0;
                if (i + 1 < height) {
                    output[i+1][j] = 0;
                }
                if (i - 1 >= 0) {
                    output[i-1][j] = 0;
                }
                if (j + 1 < width) {
                    output[i][j+1] = 0;
                }
                if (j - 1 >= 0) {
                    output[i][j-1] = 0;
                }

            } else if (input[i][j] != 0) {
                // Time Down Bombs
                if (output[i][j] > 0) {
                    output[i][j]--;
                }
            } else if (input[i][j] == 0) {
                // Set Bombs
                output[i][j] = 3;
            }
        } // For
    } // For

    return output;
}



int main() {
    int r;
    int c;
    int n;
    cin >> r >> c >> n;
    // Load Initial Grid After 1 sec
    vector< vector<int>> grid;
    for (int grid_i = 0; grid_i < r; grid_i++) {
        vector<int> tmp;
        for (int grid_j = 0; grid_j < c; grid_j++) {
            char in;
            cin >> in;
            if (in == 'O') {
                tmp.push_back(2);
            } else if (in == '.') {
                tmp.push_back(0);
            }
        }
        grid.push_back(tmp);
    } // For



    vector< vector<int>> grid1 = grid;
    grid = advanceState(grid, r, c);
    vector< vector<int>> grid2 = grid;
    grid = advanceState(grid, r, c);
    vector< vector<int>> grid3 = grid;
    grid = advanceState(grid, r, c);
    grid = advanceState(grid, r, c);
    vector< vector<int>> grid5 = grid;



    // Output
    if (n == 1) {
      print_grid(grid1);
    } else if (n % 2 == 0) {
      print_grid(grid2);
    } else if ((n - 3) % 4 == 0) {
      print_grid(grid3);
    } else {
      print_grid(grid5);
    }



    return 0;
}
