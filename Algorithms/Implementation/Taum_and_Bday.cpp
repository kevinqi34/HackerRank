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
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long b;
        long w;
        cin >> b >> w;
        long x;
        long y;
        long z;
        cin >> x >> y >> z;

        long case1 = b * x + w * y;
        long case2 = b * z + (b + w) * y;
        long case3 = w * z + (b + w) * x;

        if (case1 < case2 && case1 < case3) {
            cout << case1 << endl;
        } else if (case2 < case1 && case2 < case3) {
            cout << case2 << endl;
        } else{
            cout << case3 << endl;
        }

        /*

        cout << "C1: " << case1 << endl;
        cout << "C2: " << case2 << endl;
        cout << "C3: " << case3 << endl;
        */

    }
    return 0;
}
