#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;

        if (k != 0 && n % (2 * k) != 0) { // Check for bad cases
            cout << -1 << endl;
        } else {
            // Find Permutation
            int reset_value = k * 2;
            int counter = reset_value;
            for (int i = 1; i <= n; i++) {
                // Modify i based on k
                if (counter > k) {
                    // i = i + k
                    cout << (i + k) << " ";
                } else {
                    // i = i - k
                    cout << (i - k) << " ";
                }
                counter--; // Decrease
                if (counter <= 0) {
                    counter = reset_value;
                }
            }
            cout << endl;
        }

    }
    return 0;
}
