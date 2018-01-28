#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    long k;

    cin >> n >> k;

    // Load Data
    unordered_map<long, int> tracker;
    for (int i = 0; i < n; i++) {
        long in;
        cin >> in;
        long remain = in % k;
        auto it = tracker.find(remain);
        // Update
        if (it != tracker.end()) {
           it->second++;
        } else {
            // Insert
            pair<long, int> track (remain, 1);
            tracker.insert(track);
        }
    }

    // Find Subset
    int count = 0;
    // Case 1 - k is even
    if (k % 2 == 0) {
        // 0 Case
        if (tracker.find(0) != tracker.end()) {
            count++;
        }
        // k/2 Case
        if (tracker.find(k/2) != tracker.end()) {
            count++;
        }
        // Rest of values
        long end = k/2 - 1;
        for (long i = 1; i <= end; i++) {
            int count1 = 0;
            int count2 = 0;
            auto i1 = tracker.find(i);
            auto i2 = tracker.find(k - i);
            if (i1 != tracker.end()) {
                count1 = i1->second;
            }
            if (i2 != tracker.end()) {
                count2 = i2->second;
            }

            if (count1 > count2) {
                count+=count1;
            } else {
                count+=count2;
            }
        }
    } else {
    // Case 2 - k  is odd
        // 0 Case
        if (tracker.find(0) != tracker.end()) {
            count++;
        }
        // Rest of values
        long end = (k - 1) / 2;
        for (long i = 1; i <= end; i++) {
            int count1 = 0;
            int count2 = 0;
            auto i1 = tracker.find(i);
            auto i2 = tracker.find(k - i);
            if (i1 != tracker.end()) {
                count1 = i1->second;
            }

            if (i2 != tracker.end()) {
                count2 = i2->second;
            }

            if (count1 > count2) {
                count+=count1;
            } else {
                count+=count2;
            }
        } // For

    }



    // O(n + k);
  //  cout << "Size: " << tracker.size() << endl;
  //  cout << "Count: " << count << endl;
    cout << count << endl;




    return 0;
}
