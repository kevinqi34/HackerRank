#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

int count_num(vector <int> input, int size) {

    vector< pair<int, int>> store;

    int count = 1;
    for (int i = 0; i < size - 1; i++) {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            pair <int, int> elem;
            elem.first = input[i];
            elem.second = count;
            store.push_back(elem);
            count = 1; // Reset
        }
    } // For

    pair <int, int> elem;
    elem.first = input[size - 1];
    elem.second = count;
    store.push_back(elem);


    int max_count = 0;
    for (int i = 0; i < store.size(); i++) {
        int count = store[i].second;
        if (i < store.size() - 1) {
            if (store[i].first == store[i+1].first - 1) {
                count+=store[i+1].second;
            }
        }

        if (count > max_count) {
            max_count = count;
        }
    }

    return max_count;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }


    sort(a.begin(), a.end());
    cout << count_num(a, n) << endl;


    return 0;
}
