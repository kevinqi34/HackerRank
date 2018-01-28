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

    double p = 0;
    double neg = 0;
    double z = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            p++;
        } else if (arr[i] < 0) {
            neg++;
        } else {
            z++;
        }
    }

    cout << p/n << endl;
    cout << neg/n << endl;
    cout << z/n << endl;



    return 0;
}
