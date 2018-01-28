#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
           cin >> P[P_i];
        }


        int valid = 0;
        // Find Start Position
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (G[i][j] == P[0][0]) {
                    // Check if start position is correct
                    int good = 1;
                    for (int k = 0; k < r; k++) {
                        if (i + k < R) {
                            for (int l = 0; l < c; l++) {
                                  if (G[i+k][j+l] != P[k][l]) {
                                        good = 0;
                                        break;
                                  }
                            } // For
                            if (!good) {
                                break; // Exit
                            }
                        }
                    } // For
                    if (good) {
                        valid = 1;
                        break;
                    }
                }
            }
        }





        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }




    }
    return 0;
}
