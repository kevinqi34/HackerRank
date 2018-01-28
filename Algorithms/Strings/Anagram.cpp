#include <bits/stdc++.h>

using namespace std;

int anagram(string s){
    vector <int> count1 (26);
    vector <int> count2 (26);
    int length = s.size();
    // Error Handling
    if (length % 2 == 1) {
        return -1;
    }
    // Continue
    int i = 0;
    for (; i < length/2; i++) {
        count1[s[i] - 'a']++;
    }
    for (; i < length; i++) {
        count2[s[i] - 'a']++;
    }
    // Count changes
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum+=abs(count1[i] - count2[i]);
    }
    return sum/2;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = anagram(s);
        cout << result << endl;
    }
    return 0;
}
