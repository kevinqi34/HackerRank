#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        int m = n;

        int count = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                if (m % digit == 0) {
                    count++;
                }
            }
            n = (n - digit) / 10;
        }

        cout << count << endl;

    }
    return 0;
}
