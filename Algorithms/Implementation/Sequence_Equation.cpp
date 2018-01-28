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
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector <int> numbers;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        numbers.push_back(p);
    }

    for (int i = 1; i <= n; i++) {
        int count;
        for (int j = 0; j < n; j++) {
            if (numbers[j] == i) {
                count = j + 1;
                break;
            }
        }

        int out;
        for (int k = 0; k < n; k++) {
            if (numbers[k] == count) {
                out = k + 1;
                break;
            }
        }


        cout << out << endl;
    }




    return 0;
}
