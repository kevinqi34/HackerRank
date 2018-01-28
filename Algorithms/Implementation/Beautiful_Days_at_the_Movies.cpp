#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int reverse(int input) {
    int reversed = 0;
    while(input > 0)
    {
        reversed = reversed*10 + input%10; // take last digit of x, "appends" it to reversed
        input /= 10; // remove last digit of x
    }
    return reversed;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i;
    int j;
    int k;
    cin >> i;
    cin >> j;
    cin >> k;

    int count = 0;
    for (; i <= j; i++) {
        if (abs(i - reverse(i)) % k == 0) {
            count++;
        }
    }

    cout << count << endl;


    return 0;
}
