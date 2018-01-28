#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector <int> arr;
    for (int i = 0; i < n; i++) {
        int entry;
        cin >> entry;
        arr.push_back(entry);
    }

    sort(arr.begin(), arr.end());

    int mode = 0;
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i+1]) {
            count++;
        } else {
            if (count > mode) {
                mode = count;
            }
            count = 1;
        }
    }


    if (count > mode) {
        mode = count;
    }


    cout << n - mode << endl;



    return 0;
}
