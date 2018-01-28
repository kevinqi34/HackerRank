#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count_valleys(int n, vector<char> path_in) {

    int elevation = 0;
    int count = 0;
    int checker = 0;
    for (int i = 0; i < n; i++) {
        if (path_in[i] == 'U') {
            elevation++;
        } else if (path_in[i] == 'D') {
            elevation--;
        }

        if (elevation == -1) {
            checker = 1;
        }

        if (checker) {
            if (elevation == 0) {
                count++;
                checker = 0; // Reset
            }
        }
    } // For

    return count;

}



int main() {
    // Read input
    int n;
    vector <char> path;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char in;
        cin >> in;
        path.push_back(in);
    }

    int valleys = count_valleys(n, path);
    cout << valleys << endl;
    return 0;
}
