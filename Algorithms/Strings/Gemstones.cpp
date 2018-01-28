#include <bits/stdc++.h>
#include <string>
#include <set>

using namespace std;

int gemstones(vector <string> arr){
    string s = arr[0];
    set <char> search;
    for (char i : s) {
        search.insert(i);
    }
    int count = 0;
    for (auto i : search) {
        bool found = true;
        for (auto str : arr) {
            if (str.find(i) == std::string::npos) { // Not Found
               found = false;
               break;
            }
        }
        if (found) {
            count++;
        }
    } // For
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
