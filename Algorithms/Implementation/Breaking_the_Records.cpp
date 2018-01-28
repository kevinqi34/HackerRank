#include <bits/stdc++.h>

using namespace std;

vector < int > getRecord(vector < int > s){
    // Complete this function
    int tmp_max = s[0];
    int tmp_min = s[0];

    vector <int> result = {0, 0};

    for (auto i: s) {
        if (i > tmp_max) {
            tmp_max = i;
            result[0]++;
        }
        if (i < tmp_min) {
            tmp_min = i;
            result[1]++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    vector < int > result = getRecord(s);
    string separator = "", delimiter = " ";
    for(auto val: result) {
        cout<<separator<<val;
        separator = delimiter;
    }
    cout<<endl;
    return 0;
}
