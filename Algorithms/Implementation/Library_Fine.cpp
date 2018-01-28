#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;

    if (y1 > y2) {
        cout << 10000 << endl;
    } else {
        if (m1 > m2 && y1 == y2) {
            cout << (m1 - m2) * 500 << endl;
        } else {
            if (d1 > d2 && m1 == m2 && y1 == y2) {
                cout << (d1 - d2) * 15 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }




    return 0;
}
