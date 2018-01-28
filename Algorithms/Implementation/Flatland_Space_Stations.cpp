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

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }

    sort(c.begin(), c.end());

    // Count the largest Gap
    // First Gap
    int gap = c[0] - 0;
    for (int i = 1; i < m; i++) {
        int tmp = c[i] - c[i-1];
        if (tmp/2 > gap) {
            gap = tmp/2;
        }
    }
    // Last Gap
    if ((n - c[m - 1] - 1) > gap) {
        gap = n - c[m - 1] - 1;
    }

    cout << gap << endl;


    return 0;
}
