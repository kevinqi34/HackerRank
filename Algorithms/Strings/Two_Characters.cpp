#include <bits/stdc++.h>
#include <set>

using namespace std;

// Checks if a valid string can occur
// Returns 0 is invalid otherwise return valid string size
int check_valid(string s, char a, char b) {
    // Find Values
    char first_val;
    char second_val;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == a || s[i] == b) {
            first_val = s[i];
            break;
        }
    }
    if (first_val == a) {
        second_val = b;
    } else {
        second_val = a;
    }
    // Construct String
    int char_count = 0;
    int i = 0;
    for (; i < s.size(); i++) {
        if (char_count % 2 == 0 && s[i] == first_val) {
            char_count++;
        } else if (char_count % 2 == 1 && s[i] == second_val) {
            char_count++;
        } else if (char_count % 2 == 0 && s[i] == second_val) {
            break; // Invalid
        } else if (char_count % 2 == 1 && s[i] == first_val) {
            break; // Invalid
        }
    }

    // Passed
    if (i == s.size()) {
        return char_count;
    } else {
        return 0;
    }
}

int twoCharaters(string s) {
    int max_length = 0;
    // Find unique chars
    set <char> unique_chars;
    vector <char> unique;
    for (auto i : s) {
        unique_chars.insert(i);
    }
    for (auto i : unique_chars) {
        unique.push_back(i);
    }
    // Check all possible t-Strings
    for (int i = 0; i < unique.size(); i++) {
        for (int j = i + 1; j < unique.size(); j++) {
            int length = check_valid(s, unique[i], unique[j]);
            if (length) {
                if (length > max_length) {
                    max_length = length;
                }
            }
        } // For
    } // For

    return max_length;
}

int main() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    int result = twoCharaters(s);
    cout << result << endl;
    return 0;
}
