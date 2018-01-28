#include <bits/stdc++.h>
#include <math.h>
#include <vector>
using namespace std;

string encryption(string s) {
    int length = s.length();
    int lower_bound = floor(sqrt(length));
    int upper_bound = ceil(sqrt(length));
    // Find new grid dimensions
    int l = upper_bound;
    int w = upper_bound;
    int tmp_area = l * w;
    for (int i = lower_bound; i <= upper_bound; i++) {
        for (int j = lower_bound; j <= upper_bound; j++) {
            if (i * j >= length) {
                if (i * j < tmp_area) {
                    l = i;
                    w = j;
                    tmp_area = i * j;
                }
            }
        }
    }


    // Create new strings
    vector <string> storage (w);
    for (int i = 0; i < length; i++) {
        int index = i % w;
        storage[index]+=s[i];
    }

    /*

    cout << length << endl;
    cout << lower_bound << endl;
    cout << upper_bound << endl;
    cout << tmp_area << endl;
    cout << l << endl;
    cout << w << endl;
    */

    // Output
    string output;
    for (int i = 0; i < w; i++) {
        output+=storage[i];
        output+=" ";
    }




    return output;

}

int main() {
    string s;
    cin >> s;
    string result = encryption(s);
    cout << result << endl;
    return 0;
}
