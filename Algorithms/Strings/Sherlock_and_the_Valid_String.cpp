#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    // Find counts of letters
    vector <int> counts (26);
    vector <int> valid_counts;
    for (auto i : s) {
        counts[i - 'a']++;
    }
    for (auto c : counts) {
        if (c > 0) {
            valid_counts.push_back(c);
        }
    }
    // Check Case already valid
    int tmp = valid_counts[0];
    bool checker = true;
    for (auto c : valid_counts) {
        if (c != tmp) {
            checker = false;
            break;
        }
    }
    // Check delete 1 cases
    if (!checker) {
        for (int i = 0; i < valid_counts.size(); i++) {
            vector <int> tmp;
            for (int j = 0; j < valid_counts.size(); j++) {
                if (j != i) {
                    tmp.push_back(valid_counts[j]);
                } else {
                    tmp.push_back(valid_counts[j] - 1);
                }
            } // For

            int t = tmp[0];
            bool check = true;
            for (auto c : tmp) {
                if (c != t && c != 0) {
                    check = false;
                    break;
                }

            }

            if (check) {
                // Exit
                checker = check;
                break;
            }
        } // For
    }

    if (checker) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
