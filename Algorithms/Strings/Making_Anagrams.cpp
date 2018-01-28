#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1, string s2){
    vector <int> count1 (26);
    vector <int> count2 (26);
    // Find counts
    for (auto i : s1) {
        count1[i - 'a']++;
    }
    for (auto i : s2) {
        count2[i - 'a']++;
    }
    // Find differences
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum+=abs(count1[i] - count2[i]);
    }

    return sum;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = makingAnagrams(s1, s2);
    cout << result << endl;
    return 0;
}
