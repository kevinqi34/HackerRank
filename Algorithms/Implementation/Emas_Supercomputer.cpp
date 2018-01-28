#include <bits/stdc++.h>
#include <vector>


using namespace std;

struct plusObj {
    // Store Coordinates
    pair<int,int> center;
    // Area Information
    int area;
    int radius;
};

// Finds the maximum radius of pluses
// Input must be a 'G'
int find_max_radius(vector <vector <char>> &grid_in, int i_in, int j_in, int h_in, int w_in) {
    int current_radius = 0;
    char center_val = grid_in[i_in][j_in];
    char top_val = center_val;
    char bottom_val = center_val;
    char left_val = center_val;
    char right_val = center_val;
    while (top_val != 'B' && bottom_val != 'B' && right_val != 'B' && left_val != 'B') {
        // Advance radius
        current_radius++;
        // Top Bound
        if (i_in - current_radius >= 0) {
            top_val = grid_in[i_in - current_radius][j_in];
        } else {
            break; // Exit
        }
        // Lower Bound
        if (i_in + current_radius < h_in) {
            bottom_val = grid_in[i_in + current_radius][j_in];
        } else {
            break; // Exit
        }
        // Left Bound
        if (j_in - current_radius >= 0) {
            left_val = grid_in[i_in][j_in - current_radius];
        } else {
            break; // Exit
        }
        // Right Bound
        if (j_in + current_radius < w_in) {
            right_val = grid_in[i_in][j_in + current_radius];
        } else {
            break; // Exit
        }
    } // While
    return (current_radius - 1);
}

// Create plusObj
// Takes in center and radius as inputs
plusObj create_plusObj(int i_in, int j_in, int rad_in) {
    plusObj out;
    // Create Coordinates
    out.center.first = i_in;
    out.center.second = j_in;
    // Store other info
    out.radius = rad_in;
    out.area = 1 + rad_in * 4;
    // Return
    return out;
}



// Finds all possible pluses
vector <plusObj> find_all_pluses(vector <vector <char>> &grid_in, int height_in, int width_in) {
    vector <plusObj> out;
    // Find starting coordinates
    for (int i = 0; i < height_in; i++) {
        for (int j = 0; j < width_in; j++) {
            // Find maximum radius for valid coordinates
            if (grid_in[i][j] == 'G') {
                int radius = find_max_radius(grid_in, i, j, height_in, width_in);
                while (radius >= 0) {
                    plusObj tmp = create_plusObj(i, j, radius);
                    out.push_back(tmp); // Store
                    radius--;
                } // While
            }
        } // For
    } // For

    return out;
}

// Checks if two pluses overlap each other
// Return true if overlap and false if no overlap
bool overlap(plusObj a, plusObj b) {
    // Create tiles for a
    vector<pair<int, int>> a_tiles;
    a_tiles.push_back(a.center);
    int rad_a = a.radius;
    while (rad_a > 0) {
        pair<int,int> top;
        top.first = a.center.first - rad_a;
        top.second = a.center.second;
        pair<int,int> bottom;
        bottom.first = a.center.first + rad_a;
        bottom.second = a.center.second;
        pair<int,int> left;
        left.first = a.center.first;
        left.second = a.center.second - rad_a;
        pair<int,int> right;
        right.first = a.center.first;
        right.second = a.center.second + rad_a;
        a_tiles.push_back(top);
        a_tiles.push_back(bottom);
        a_tiles.push_back(left);
        a_tiles.push_back(right);
        rad_a--;
    }
    // Create tiles for b
    vector<pair<int, int>> b_tiles;
    b_tiles.push_back(b.center);
    int rad_b = b.radius;
    while (rad_b > 0) {
        pair<int,int> top;
        top.first = b.center.first - rad_b;
        top.second = b.center.second;
        pair<int,int> bottom;
        bottom.first = b.center.first + rad_b;
        bottom.second = b.center.second;
        pair<int,int> left;
        left.first = b.center.first;
        left.second = b.center.second - rad_b;
        pair<int,int> right;
        right.first = b.center.first;
        right.second = b.center.second + rad_b;
        b_tiles.push_back(top);
        b_tiles.push_back(bottom);
        b_tiles.push_back(left);
        b_tiles.push_back(right);
        rad_b--;
    }
    // Check for overlaps
    bool is_over = false;
    for (int i = 0; i < a_tiles.size(); i++) {
        bool checker = false;
        for (int j = 0; j < b_tiles.size(); j++) {
           if (a_tiles[i].first == b_tiles[j].first && a_tiles[i].second == b_tiles[j].second) {
            checker = true;
            is_over = true;
            break;
           }
        }
        if (checker) {
            break;
        }
    } // For

    return is_over;
}

// Find Maximum Product
int find_max_product(vector <plusObj> &plus_in) {
    int n = plus_in.size();
    int current_max = 0;
    // Iterate through n(n-1)/2 possible
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
           if (!overlap(plus_in[i], plus_in[j])) {
             int product = plus_in[i].area * plus_in[j].area;
             if (product > current_max) {
                 current_max = product;
             }
           }
        } // For
    } // For

    return current_max;
}



int main() {
    int h;
    int w;
    cin >> h >> w;
    vector <vector <char>> grid; // Store Grid
    for (int i = 0; i < h; i++) {
        vector <char> tmp;
        for (int j = 0; j < w; j++) {
            char in;
            cin >> in;
            tmp.push_back(in);
        }
        grid.push_back(tmp);
    }

    // Find Valid Pluses
    vector<plusObj> results = find_all_pluses(grid, h, w);
    cout << find_max_product(results) << endl;
    return 0;
}
