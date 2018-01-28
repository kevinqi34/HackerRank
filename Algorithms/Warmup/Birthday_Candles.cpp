#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Complete this function
    int num_tracker = 0;
    int max = ar[0];

    for (int i = 0; i < n; i++) {
       // Find new max
        if (ar[i] > max) {
            max = ar[i];
            num_tracker = 0;
        }

        // Count
        if (ar[i] == max) {
            num_tracker++;
        }
    }

    return num_tracker;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
