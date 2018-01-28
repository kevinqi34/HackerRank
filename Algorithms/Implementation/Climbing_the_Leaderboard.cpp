#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0; scores_i < n; scores_i++){
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       cin >> alice[alice_i];
    }
    // Write Your Code Here
    vector <int> results;
    int rank = 1;
    int alice_counter = m - 1;
    for (int i = 0; i < n; i++) {
        int alice_value = alice[alice_counter];
        while (alice_value >= scores[i]) {
            results.push_back(rank);
            alice_counter--;
            alice_value = alice[alice_counter];
        }
        // Find Rank
        if (i < n-1 && scores[i] == scores[i+1]) {
            // DO NOTHING
        } else {
            rank++;
        }
    }

    // Last Rank
    while (alice_counter >= 0) {
        results.push_back(rank);
        alice_counter--;
    }


    for (int i = results.size() - 1; i >= 0; i--) {
        cout << results[i] << endl;
    }


    return 0;
}
