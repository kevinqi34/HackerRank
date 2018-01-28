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
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }


    int jump_count = 0;
    int i = 0;
    while (i < n - 1) {
        if (c[i + 2] == 0) {
            i = i + 2;
        } else if (c[i + 1] == 0) {
            i = i + 1;
        }
        jump_count++;
    }

    cout << jump_count << endl;



    return 0;
}
