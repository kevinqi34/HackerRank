#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int ppl = 5;
    int likes = 0;
    for (int i = 0; i < n; i++) {
        likes+=floor(ppl/2);
        // Change ppl
        ppl = (floor(ppl/2) * 3);
    }

    cout << likes << endl;

    return 0;
}
