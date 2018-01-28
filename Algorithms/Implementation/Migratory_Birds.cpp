#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    int count = 1;
    int mode = ar[0];
    int max = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] == ar[i + 1]) {
            count++;
            if (count > max) {
                mode = ar[i];
                max = count;
            }
        } else {
            count = 1; // Reset
        }
    } // For

    return mode;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }

    sort(ar.begin(), ar.end());
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
