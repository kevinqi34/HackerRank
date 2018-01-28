#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;

    int space = n - 1;
    int wall = 1;


    for (int i = 0; i < n; i++) {
        // Space
        for (int j = 0; j < space; j++) {
            cout << " ";
        }
        // Wall
        for (int k = 0; k < wall; k++) {
            cout << "#";
        }

        cout << endl;
        space--;
        wall++;
    }

    return 0;
}
