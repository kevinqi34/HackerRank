#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    string new_s;
    for (int i = 0; i < n; i++) {
        int tmp = (int) s[i];
        if (tmp >= 65 && tmp <= 90) { // Upper Case
           int rot = (tmp - 65 + k) % 26;
           char nch = (char) (rot + 65);
           new_s+=nch;
        } else if (tmp >= 97 && tmp <= 122) { // Lower Case
           int rot = (tmp - 97 + k) % 26;
           char nch = (char) (rot + 97);
           new_s+=nch;
        } else {
            // Remain the same
            new_s+=s[i];
        }

    }

    cout << new_s << endl;


    return 0;


}
