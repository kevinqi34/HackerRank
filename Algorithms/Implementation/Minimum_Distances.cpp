#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int minimumDistances(vector <int> a) {
    // O(1) search
    unordered_map <int, int> last_index;
    int min = a.size();
    for (int i = 0; i < a.size(); i++) {
        // If not in map
        if (last_index.find(a[i]) == last_index.end()) {
            // Add to map
            last_index.insert({a[i], i});
        } else {
            auto it = last_index.find(a[i]);
            int distance = i - it->second;
            if (distance < min) {
                min = distance;
            }

        }

    }

    if (min == a.size()) {
        return -1;
    }

    return min;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    int result = minimumDistances(a);
    cout << result << endl;
    return 0;
}
