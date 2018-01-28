#include <bits/stdc++.h>

using namespace std;

// Advance iterators
void advance_iterator(int &iterate_x, int &iterate_y, int &height, int &width, int &start_index_x, int &start_index_y){
    // Go Right First
    if (iterate_x == start_index_x && iterate_y < width - 1) {
        iterate_y++;
    } else if (iterate_x < height - 1 && iterate_y == width - 1) {
        iterate_x++; // Advance down
    } else if (iterate_x == height - 1 && iterate_y > start_index_y) {
        iterate_y--; // Advance left
    } else if (iterate_x > start_index_x && iterate_y == start_index_y) {
        iterate_x--; // Advance up
    }
}


// Splits the matrix into lists that represent each layer of the matrix sorta like an onion
vector < vector<int> > splitMatrix(vector < vector<int> > &matrix_in) {
    int height = matrix_in.size(); // Initial height
    int width = matrix_in[0].size(); // Initial width
    vector < vector<int> > list; // Output list
    int start_index_x = 0;
    int start_index_y = 0;
    // Loop through layers of the matrix
    while (start_index_x != height && start_index_y != width) {
        // Store one layer
        vector <int> layer;
        int iterate_x = start_index_x;
        int iterate_y = start_index_y;
        // Run changes once before loop
        layer.push_back(matrix_in[iterate_x][iterate_y]); // Add to layer
        advance_iterator(iterate_x, iterate_y, height, width, start_index_x, start_index_y);
        while(iterate_x != start_index_x || iterate_y != start_index_y) {
            // Add to layer
            layer.push_back(matrix_in[iterate_x][iterate_y]);
            advance_iterator(iterate_x, iterate_y, height, width, start_index_x, start_index_y);
        } // While
        // Increment start_index and adjust bounds
        start_index_x++;
        start_index_y++;
        height--;
        width--;
        list.push_back(layer);
    }

    return list;
}

// Rebuilt matrix with rotated lists
void rebuild_matrix(vector < vector<int> > &matrix_out, vector < vector<int> > &layers) {
    // Establish Bounds
    int height = matrix_out.size();
    int width = matrix_out[0].size();
    int start_index_x = 0;
    int start_index_y = 0;
    // Build
    for (auto layer : layers) {
        int index = 0;
        int iterate_x = start_index_x;
        int iterate_y = start_index_y;
        // Run changes once before loop
        matrix_out[iterate_x][iterate_y] = layer[index];
        advance_iterator(iterate_x, iterate_y, height, width, start_index_x, start_index_y);
        index++;
        while(iterate_x != start_index_x || iterate_y != start_index_y) {
           matrix_out[iterate_x][iterate_y] = layer[index];
           advance_iterator(iterate_x, iterate_y, height, width, start_index_x, start_index_y);
           index++;
        }
        start_index_x++;
        start_index_y++;
        height--;
        width--;
    } // For
}

// Rotates a layer by r
void rotate_layer(vector <int> &input, int r_in) {
    int bound = input.size();
    vector<int> tmp = input;
    for (int i = 0; i < bound; i++) {
        int new_index = (i + bound - (r_in % bound)) % bound;
        input[new_index] = tmp[i];
    }
}

// Run Rotations
void matrixRotation(vector < vector<int> > matrix, int r_in, int m_in, int n_in) {
    // Create output object
    vector< vector<int> > matrix_out(m_in,vector<int>(n_in));
    // Split matrix into vector lists
    vector < vector<int> > layers = splitMatrix(matrix);
    // Modify Layers
    for (int i = 0; i < layers.size(); i++) {
        rotate_layer(layers[i], r_in); // Rotate
    }
    // Recreate matrix
    rebuild_matrix(matrix_out, layers);
    // Output
    for (auto i : matrix_out) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }


}

// Main()
int main() {
    int m;
    int n;
    int r;
    cin >> m >> n >> r;
    vector< vector<int> > matrix(m,vector<int>(n));
    for(int matrix_i = 0;matrix_i < m;matrix_i++){
       for(int matrix_j = 0;matrix_j < n;matrix_j++){
          cin >> matrix[matrix_i][matrix_j];
       }
    }
    matrixRotation(matrix,r,m,n);
    return 0;
}
