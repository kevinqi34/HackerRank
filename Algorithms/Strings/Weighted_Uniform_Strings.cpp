#include <vector>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector <bool> possible(10e7);
    // Find possible values
    for(int i = 0; i < s.length(); i++) {
        int sum = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[i+j] == s[i]) {
                sum+=s[i+j] - 96;
            } else {
                break;
            }
        }
        possible[sum] = true;
    } // For


    // Output
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        if (possible[x]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
