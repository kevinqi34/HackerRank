#include <bits/stdc++.h>

using namespace std;

string larrysArray(vector <int> A) {
    vector <int> tracker; // Tracks past stores
    int num_of_inversions = 0;
    // Count number of inversions
    for (auto i : A) {
        int subtract_amount = 0;
        for (auto j : tracker) {
            if (j < i) {
                subtract_amount++;
            }
        }
        // Count
        int inv = i - 1 - subtract_amount;
        num_of_inversions+=inv;
        // Store
        tracker.push_back(i);
    }

    if (num_of_inversions % 2 == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int A_i = 0; A_i < n; A_i++){
           cin >> A[A_i];
        }
        string result = larrysArray(A);
        cout << result << endl;
    }
    return 0;
}
