#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> numbers = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine"
};

int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;

    if (m < 30) { // First Half
        if (m == 0) {
            cout << numbers[h] << " o' clock" << endl;
        } else if (m == 15) {
            cout << "quarter past " << numbers[h] << endl;
        } else {
            cout << numbers[m] << " minutes past " << numbers[h] << endl;

        }

    } else { // Second Half
        if (m == 30) {
            cout << "half past " << numbers[h] << endl;
        } else if (m == 45) {
            cout << "quarter to " << numbers[h + 1] << endl;
        } else {
            cout << numbers[60 - m] << " minutes to " << numbers[h+1] << endl;

        }

    }




    return 0;
}
