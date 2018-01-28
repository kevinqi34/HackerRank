#include <bits/stdc++.h>

using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    // Complete this function
    int num_of_x = 0;
    for (int i = 1; i <= 100; i++) {
        int check1 = 1;
        int check2 = 1;
        for (auto s1 : a) {
            if (i % s1 != 0) {
                check1 = 0;
                break;
            }
        }

        if (check1) {
            for (auto s2: b) {
                if (s2 % i != 0) {
                    check2 = 0;
                    break;
                }
            }
        }


        if (check1 && check2) {
            num_of_x++;
        }
    } // For

    return num_of_x;



}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
