#include <iostream>
#include <vector>

using namespace std;

int convert_ascii_to_int(char in) {
    int return_val = (int) in;
    if (return_val >= 97) {
        return_val-=97;
    } else {
        return_val-=65;
    }
    return return_val;
}


int main() {
    vector<int> counts(26);
    // Get input
    string in;
    for (int i = 0; i < 1000; i++) {
        char ch;
        cin >> ch;
        in+=ch;
    }
    // Find counts
    for (auto i : in) {
        counts[convert_ascii_to_int(i)]++;
    }
    // Check
    bool checker = true;
    for (auto i : counts) {
        if (i == 0) {
            checker = false;
            break;
        }
    }
    // Output
    if (checker) {
        cout << "pangram" << endl;
    } else {
        cout << "not pangram" << endl;
    }



    return 0;
}
