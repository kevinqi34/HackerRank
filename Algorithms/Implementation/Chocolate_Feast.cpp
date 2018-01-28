#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;

        int wrappers = n / c;
        int total = wrappers;
        while (wrappers >= m) {
            int tmp = wrappers / m;
            total+=tmp;
            wrappers = tmp + wrappers % m;

        }
        cout << total << endl;


    }
    return 0;
}
