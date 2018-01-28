#include <bits/stdc++.h>

using namespace std;

int beautifulTriplets(int d, vector <int> arr) {
    int count = 0;
    int it = 0;
    int root = arr[it];
    int leaf1 = root + d;
    int leaf2 = root + 2 * d;
    int last_elem = arr[arr.size() - 1];
    while (leaf2 <= last_elem) {
        if (root )


    }
    cout << last_elem << endl;



    return 0;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = beautifulTriplets(d, arr);
    cout << result << endl;
    return 0;
}
