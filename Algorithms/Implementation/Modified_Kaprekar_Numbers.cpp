#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long p, q;
    cin >> p >> q;
    int checker = 0;
    for (; p <= q; p++) {
        long p_size = 0;
        long counter = p;
        while (counter) {
            counter/=10;
            p_size++;
        }

        long n = p * p;
        long divider = pow(10, p_size);
        long sum = n % divider + n / divider;
        if (sum == p) {
         checker = 1;
         cout << p << " ";
        }




    }

    if (!checker) {
        cout << "INVALID RANGE" << endl;
    }

    return 0;
}
