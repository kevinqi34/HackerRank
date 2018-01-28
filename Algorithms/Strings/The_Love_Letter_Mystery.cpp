#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int theLoveLetterMystery(string s){
    int length = s.size() / 2;
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            int diff = abs(s[i] - s[s.size() - i - 1]);
            count+=diff;
        }
    } // For
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}
