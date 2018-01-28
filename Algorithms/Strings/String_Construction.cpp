#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s) {
    vector <int> count (26);
    for (auto i : s) {
        count[i - 'a']++;
    }

    int return_val = 0;
    for (auto i : count) {
        if (i) {
            return_val++;
        }
    }

    return return_val;

}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = stringConstruction(s);
        cout << result << endl;
    }
    return 0;
}
