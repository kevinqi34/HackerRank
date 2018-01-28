#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    // Load Matrix
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }

    int col1_counter = 0;
    int col2_counter = n - 1;
    int diag1 = 0;
    int diag2 = 0;
    for (int row = 0; row < n; row++) {
        diag1+=a[row][col1_counter];
        diag2+=a[row][col2_counter];
        col1_counter++;
        col2_counter--;
    }


    cout << abs(diag1 - diag2) << endl;

    return 0;
}
