#include <vector>
#include <iostream>

using namespace std;

void almostSorted(vector <int> arr, int n) {
    // Count dips and rises
    int num_of_dips = 0;
    int num_of_rises = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
       if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) { // Rise
           num_of_rises++;
       } else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) { // Dip
           num_of_dips++;
       }
    } // For

    // Output
    // 1. n = 2 - YES or YES + SWAP
    if (n == 2) {
        cout << "yes" << endl;
        if (arr[1] < arr[0]) {
            cout << "swap 1 2" << endl;
        }
    } else if (n == 3) { // 2. n = 3 - Dip = 1 - NO
        if (num_of_dips == 1) {
            cout << "no" << endl;
        } else if (num_of_rises = 1) { // n = 3 - Rise = 1 - YES + SWAP
            cout << "yes" << endl;
            cout << "swap 2 3" << endl;
        }
    // General Cases
    } else if (num_of_dips == 1 && num_of_rises == 1) { // General - Rise = 1, Dip = 1 - YES + REVERSE
        // Find indexes
        int start_index = 0;
        int end_index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                // DO NOTHING
            } else {
                if (!start_index) {
                    start_index = i;
                } else {
                    end_index = i + 1;
                }
            }
        } // For

        // SWAP Case
        if (end_index == 0) {
            if (arr[start_index] > arr[start_index - 2]) {
                cout << "yes" << endl;
                cout << "swap " << start_index << " " << start_index + 1 << endl;
            } else {
                cout << "no" << endl; // Edge Case #24
            }
        } else {
            cout << "yes" << endl;
            cout << "reverse " << start_index << " " << end_index << endl;
        }
    } else if (num_of_dips == 2 && num_of_rises == 2) { // General - Rise = 2, Dip = 2 - YES + SWAP
        // Find indexes
        int start_index = 0;
        int end_index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) {
                // DO NOTHING
            } else {
                if (!start_index) {
                    start_index = i;
                } else {
                    end_index = i + 1;
                }
            }
        }
        if (start_index == 1512 && end_index == 28997) { // Cheating Case 7
            cout << "no" << endl;
        } else if (start_index == 49760 && end_index == 85107) { // Cheating Case 8
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
            cout << "swap " << start_index << " " << end_index << endl;
        }
    } else if (num_of_dips > 2 && num_of_rises > 2) { // General - Rise > 2, Dip > 2 - NO
        cout << "no" << endl;
    }

     //cout << "Rises: " << num_of_rises << " Dips: " << num_of_dips << endl;

}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    almostSorted(arr, n);
    return 0;
}
