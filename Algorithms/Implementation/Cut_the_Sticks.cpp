#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    // Sort
    sort(arr.begin(), arr.end(), std::greater<int>());


    while (!arr.empty()) {
        int count = arr.size();
        int cut_value = arr.back();
        for (int i = 0; i < count; i++) {
            arr[i]-=cut_value;
            if (arr[i] <= 0) {
                arr.pop_back();
            }
        }
        cout << count << endl;
    }

    return 0;
}
