#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s){
    vector <int> counts (26);
    for (auto i : s) {
        counts[i - 'a']++;
    }
    // Check if palindrome
    int odd_count = 0;
    for (auto i : counts) {
        if (i % 2 == 1) {
            odd_count++;
        }
    }
    // Output
    if (odd_count == 1 || odd_count == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    string s;
    cin >> s;
    string result = gameOfThrones(s);
    cout << result << endl;
    return 0;
}
