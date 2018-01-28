#include <bits/stdc++.h>

using namespace std;

int bonAppetit(int n, int k, int b, vector <int> ar) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum+=ar[i];
    }

    int proper = (sum - ar[k]) / 2;
    if (proper == b) {
        return 0;
    } else {
        return b - proper;
    }

}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int b;
    cin >> b;
    int result = bonAppetit(n, k, b, ar);
    if (result) {
        cout << result << endl;
    } else {
        cout << "Bon Appetit" << endl;
    }
    return 0;
}
