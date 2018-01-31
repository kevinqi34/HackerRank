#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct string_compare {
    bool operator() (const string &a, const string &b) {
        if (a.size() == b.size()) {
            return a > b;
        } else if (a.size() > b.size()){
            return true;
        } else {
            return false;
        }
    }
};



int main(){
    int n;
    cin >> n;
    vector<string> unsorted(n);
    for(int unsorted_i = 0; unsorted_i < n; unsorted_i++){
       cin >> unsorted[unsorted_i];
    }
    // your code goes here
    sort(unsorted.begin(), unsorted.end(), string_compare());
    for (int i = 0; i < n; i++) {
        cout << unsorted[n - i - 1] << endl;
    }
    return 0;
}
