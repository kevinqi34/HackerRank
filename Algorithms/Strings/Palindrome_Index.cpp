#include <bits/stdc++.h>

using namespace std;


// Checks if a string is a palindrome
bool palindrome(string s) {
    bool checker = true;
    int length = s.size() / 2;
    for (int i = 0; i < length; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            checker = false;
            break;
        }
    }
    return checker;
}



int palindromeIndex(string s){
    if (palindrome(s)) {
        // Already Palindrome
        return -1;
    } else {
        int index = 0;
        // Check starting from the ends
        int left_index = 0;
        int right_index = s.size() - 1;
        while (left_index < right_index) {
            if (s[right_index] != s[left_index]) {
                int mid = right_index - left_index;
                string check = s.substr(left_index, mid);
                if (palindrome(check)) {
                    index = right_index;
                } else {
                    index = left_index;
                }
                break;
            }
            // Increment
            left_index++;
            right_index--;
        } // While
        return index;
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
