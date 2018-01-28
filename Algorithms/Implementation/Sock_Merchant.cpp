#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int sockMerchant(int n, vector <int> ar) {
    int ret_val = 0;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (ar[i] == ar[i+1]) {
            count++;
        } else {
            ret_val+=(count/2);
            count = 1;
        }
    }

    return ret_val + count/2;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }

    sort(ar.begin(), ar.end());
    int result = sockMerchant(n, ar);
    cout << result << endl;
    return 0;
}
