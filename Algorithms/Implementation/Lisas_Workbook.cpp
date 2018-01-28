#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<int> problems;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        problems.push_back(tmp);
    }

    int page_counter = 0;
    int problem_counter = 0;
    int match = 0;
    for (auto i : problems) {
        for (int it = 0; it < i; it++) {
            problem_counter++;
            if (it % k == 0) {
                page_counter++;
            }
            if (problem_counter == page_counter){
                match++;
            }
        }
        problem_counter = 0; // Revert
    }

    cout << match << endl;


    return 0;
}
