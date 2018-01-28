#include <bits/stdc++.h>

using namespace std;

string hackerrankInString(string s) {
    string check = "hackerrank";
    int len = check.size();
    int index= 0;
    bool found = false;
    for (auto i : s) {
        if (i == check[index]) {
            index++;
        }
        if (index == len) {
            found = true;
            break;
        }
    }

    if (found) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = hackerrankInString(s);
        cout << result << endl;
    }
    return 0;
}
