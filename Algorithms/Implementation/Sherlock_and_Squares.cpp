#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        int start_value = a;
        int check = 0;
        for (; a <= b; a++) {
            if (sqrt(a) == ceil(sqrt(a))) {
                start_value = sqrt(a);
                count++;
                check = 1;
                break;
            }
        }

        if (check) {
            start_value++;
            int power = start_value * start_value;
            while (power <= b) {
                start_value++;
                count++;
                power = start_value * start_value;
            }
        }
        cout << count << endl;


    }


    return 0;
}
