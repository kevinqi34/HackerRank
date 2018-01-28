#include <bits/stdc++.h>
#include <string>

using namespace std;

void separateNumbers(string s) {
    int length = s.length();
    int test_length = length / 2;
    // Create test string
    int start_length = 1;
    while (start_length <= test_length) {
        string test = s.substr(0, start_length);
        long starting_val = stol(test);
        long save_val = starting_val;
        while (test.length() < length) {
            starting_val++;
            string add = to_string(starting_val);
            test+=add;
        }
        if (test.compare(s) == 0) {
            cout << "YES " << save_val << endl;
            break;
        }
        start_length++;
    }

    if (start_length > test_length) {
        cout << "NO" << endl;
    }
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        separateNumbers(s);
    }
    return 0;
}
