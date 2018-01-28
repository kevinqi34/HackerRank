#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }

    // O(N)
    // Find Min, Max and Sum

    int64_t sum = 0;
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < 5; i++) {
        sum+=arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }



    // Output

    cout << sum - max << " ";
    cout << sum - min << endl;



    return 0;
}
