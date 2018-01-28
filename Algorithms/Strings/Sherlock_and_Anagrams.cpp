#include <bits/stdc++.h>

using namespace std;


// If anagram -- checks if 2 strings are anagrams of each other
bool if_anagram(string a, string b) {
    vector<int> count1 (26);
    vector<int> count2 (26);
    for (auto i : a) {
        count1[i - 'a']++;
    }

    for (auto i : b) {
        count2[i - 'a']++;
    }

    bool out = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            out = false;
            break;
        }
    }
    return out;
}



int sherlockAndAnagrams(string s){
    int count = 0;
    // Check pairs of possible substrings based on length
    int substr_len = 1;
    int str_len = s.size();
    while (substr_len < str_len) {
        // Find pairs
        for (int i = 0; i < str_len - substr_len; i++) {
            string check1 = s.substr(i, substr_len);
            for (int j = i + 1; j < str_len - substr_len + 1; j++) {
                string check2 = s.substr(j, substr_len);
                if (if_anagram(check1, check2)) {
                    count++;
                }
            } // For
        } // For

        substr_len++;
    } // While

    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}
