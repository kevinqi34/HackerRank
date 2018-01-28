#include <bits/stdc++.h>

using namespace std;

string funnyString(string s) {
    for (int i = 1; i < s.length(); i++) {
        int front_dif = abs(s[i] - s[i-1]);
        int back_dif = abs(s[s.length() - i] - s[s.length() - i - 1]);
        if (back_dif != front_dif) {
            return "Not Funny";
        }
    }
    return "Funny";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}
