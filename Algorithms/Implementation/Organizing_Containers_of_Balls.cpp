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
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector <int> c_totals (n);
        vector <int> b_totals (n);

        vector< vector<int> > M(n,vector<int>(n));
        for(int M_i = 0;M_i < n; M_i++){
            int count = 0;
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
              count+=M[M_i][M_j];
              b_totals[M_j]+=M[M_i][M_j];
           }
           c_totals[M_i] = count;
        }

        sort(c_totals.begin(), c_totals.end());
        sort(b_totals.begin(), b_totals.end());

        int checker = 0;
        for (int i = 0; i < n; i++) {
            if (c_totals[i] != b_totals[i]) {
                checker = 1;
                break;
            }
        }

        if (checker) {
            cout << "Impossible" << endl;
        } else {
            cout << "Possible" << endl;
        }


    }
    return 0;
}
