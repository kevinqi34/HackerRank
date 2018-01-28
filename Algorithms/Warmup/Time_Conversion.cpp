#include <bits/stdc++.h>
#include <string>

using namespace std;

string timeConversion(string s) {
    // Complete this function
    // Split String
    string hours = s.substr(0,2);
    string end = s.substr(2,6);
    string comp = s.substr(8,2);

    int h = stoi(hours);

    if (comp.compare("PM") == 0 && h < 12) {
        h+=12;
        hours = to_string(h);
    } else if (comp.compare("AM") == 0 && h >= 12) {
        h-=12;
        if (h < 10) {
            hours = "0" + to_string(h);
        } else {
            hours = to_string(h);
        }
    } 
    return hours + end;

}

int main() {
    string s;
    cin >> s;
    string result = timeConversion(s);
    cout << result << endl;
    return 0;
}
