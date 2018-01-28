#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    // Complete this function
    for (int i = 1; i < s.length(); i++) {
       if (s[i] == s[i-1]) {
           // Delete
           s = s.substr(0, i - 1) + s.substr(i + 1);
           i = 0; // Restart
       }
    }

    if (s.length() == 0) {
        return "Empty String";
    } else {
        return s;
    }

}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
